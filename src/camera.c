#include "camera.h"

#include <assert.h>

#include "ppm.h"
#include "utils.h"

camera_t camera_create(unsigned int image_width, double aspect_ratio) {
  camera_t result;
  result.samples_per_pixel = 100;
  result.max_depth = 50;

  result.image_width = image_width;
  result.aspect_ratio = aspect_ratio;

  int img_height = image_width / aspect_ratio;
  result.image_height = (img_height < 1) ? 1 : img_height;

  result.center = vec3_create(0, 0, 0);

  double focal_length = 1.0;
  double viewport_height = 2.0;
  double viewport_width = viewport_height * ((double)image_width / result.image_height);

  vec3_t viewport_u = vec3_create(viewport_width, 0, 0);
  vec3_t viewport_v = vec3_create(0, -viewport_height, 0);

  result.pixel_delta_u = vec3_div(viewport_u, result.image_width);
  result.pixel_delta_v = vec3_div(viewport_v, result.image_height);

  vec3_t viewport_upper_left = vec3_sub(vec3_sub(vec3_sub(result.center, vec3_create(0, 0, focal_length)), vec3_div(viewport_u, 2)), vec3_div(viewport_v, 2));
  result.pixel_upper_left = vec3_add(viewport_upper_left, vec3_scale(vec3_add(result.pixel_delta_u, result.pixel_delta_v), 0.5));


  return result;
}

void render(camera_t* camera, hittable_list_t* world, const char* filepath) {
  PPM render_result = ppm_create(camera->image_width, camera->image_height);
  for (unsigned int y = 0; y < camera->image_height; y++) {
    for (unsigned int x = 0; x < camera->image_width; x++) {
      color_t pixel_color = col_create(0, 0, 0);
      for (unsigned int sample = 0; sample < camera->samples_per_pixel; sample++) {
        ray_t ray = ray_get(camera, x, y);
        pixel_color = vec3_add(pixel_color, ray_color(&ray, camera->max_depth, world));
      }

      pixel_color = vec3_scale(pixel_color, 1.0f / camera->samples_per_pixel);

      // Gamma correction
      pixel_color = vec3_map(pixel_color, linear_to_gamma);

      interval_t intensity = interval_create(0.0, 1.0);
      pixel_color.r = interval_clamp(&intensity, pixel_color.r);
      pixel_color.g = interval_clamp(&intensity, pixel_color.g);
      pixel_color.b = interval_clamp(&intensity, pixel_color.b);

      ppm_set(&render_result, x, y, pixel_color);
    }
  }
  ppm_write(&render_result, filepath);
  ppm_free(&render_result);
}

color_t ray_color(ray_t* ray, unsigned int depth, hittable_list_t* world) {
  assert(ray);
  assert(world);

  if (depth <= 0) {
    return col_create(0, 0, 0);
  }

  hit_record_t hit_record;
  if (hittable_list_hit(world, ray, &(interval_t){.min = 0.0001, .max = INFINITY}, &hit_record)) {
    vec3_t direction = vec3_add(hit_record.normal, vec3_create_random_unit());
    return vec3_scale(ray_color(&(ray_t){hit_record.point, direction}, depth - 1, world), 0.5);
  }

  // Background
  vec3_t unit_vec = vec3_normalised(ray->direction);
  double a = (unit_vec.y + 1.00) * 0.5;
  return vec3_add(vec3_scale(col_create(1.0, 1.0, 1.0), 1.00 - a), vec3_scale(col_create(0.5, 0.7, 1.0), a));
}

ray_t ray_get(camera_t* camera, unsigned int x, unsigned int y) {
  vec3_t pixel_center = vec3_add(camera->pixel_upper_left, vec3_add(vec3_scale(camera->pixel_delta_u, x), vec3_scale(camera->pixel_delta_v, y)));

  double px = -0.5 + rand_double(0.0, 1.0);
  double py = -0.5 + rand_double(0.0, 1.0);
  vec3_t rand_pixel = vec3_add(vec3_scale(camera->pixel_delta_u, px), vec3_scale(camera->pixel_delta_v, py));
  vec3_t pixel_sample = vec3_add(pixel_center, rand_pixel);

  vec3_t ray_direction = vec3_sub(pixel_sample, camera->center);

  ray_t ray = {camera->center, ray_direction};

  return ray;
}