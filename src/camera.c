#include "camera.h"

#include <assert.h>

#include "ppm.h"

camera_t camera_create(unsigned int image_width, double aspect_ratio) {
  camera_t result;
  result.image_width = image_width;
  result.aspect_ratio = aspect_ratio;

  int img_height = image_width / aspect_ratio;
  result.image_height = (img_height < 1) ? 1 : img_height;

  result.center = vec3_create(0, 0, 0);

  double focal_length = 1.0f;
  double viewport_height = 2.0f;
  double viewport_width = viewport_height * ((double)image_width / result.image_height);

  vec3_t viewport_u = vec3_create(viewport_width, 0, 0);
  vec3_t viewport_v = vec3_create(0, -viewport_height, 0);

  result.pixel_delta_u = vec3_div(viewport_u, result.image_width);
  result.pixel_delta_v = vec3_div(viewport_v, result.image_height);

  vec3_t viewport_upper_left = vec3_sub(vec3_sub(vec3_sub(result.center, vec3_create(0, 0, focal_length)), vec3_div(viewport_u, 2)), vec3_div(viewport_v, 2));
  result.pixel_upper_left = vec3_add(viewport_upper_left, vec3_scale(vec3_add(result.pixel_delta_u, result.pixel_delta_v), 0.5f));

  return result;
}

void render(camera_t* camera, hittable_list_t* world, const char* filepath) {
  PPM render_result = ppm_create(camera->image_width, camera->image_height);
  for (unsigned int y = 0; y < camera->image_height; y++) {
    for (unsigned int x = 0; x < camera->image_width; x++) {
      vec3_t pixel_center = vec3_add(camera->pixel_upper_left, vec3_add(vec3_scale(camera->pixel_delta_u, x), vec3_scale(camera->pixel_delta_v, y)));
      vec3_t ray_direction = vec3_sub(pixel_center, camera->center);

      ray_t ray = {camera->center, ray_direction};

      color_t ray_col = ray_color(&ray, world);

      ppm_set(&render_result, x, y, ray_col);
    }
  }
  ppm_write(&render_result, filepath);
}

color_t ray_color(ray_t* ray, hittable_list_t* world) {
  assert(ray);
  assert(world);

  hit_record_t hit_record;
  if (hittable_list_hit(world, ray, &(interval_t){.min = 0, .max = INFINITY}, &hit_record)) {
    // scale the normal to be between 0 and 1
    return vec3_scale(vec3_add(hit_record.normal, vec3_create(1, 1, 1)), 0.5);
  }

  vec3_t unit_vec = vec3_normalised(ray->direction);
  double a = (unit_vec.y + 1.00f) * 0.5f;
  return vec3_add(vec3_scale(col_create(1.0f, 1.0f, 1.0f), 1.00f - a), vec3_scale(col_create(0.5f, 0.7f, 1.0f), a));
}