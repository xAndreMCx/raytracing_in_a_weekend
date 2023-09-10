#include <assert.h>
#include <math.h>
#include <stdio.h>

#include "hittable_list.h"
#include "ppm.h"
#include "ray.h"
#include "sphere.h"
#include "vec.h"

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

int main(void) {
  // Image
  double aspect_ratio = 16.f / 9.0f;
  unsigned int width = 400;
  unsigned int height = width / aspect_ratio;
  height = (height < 1) ? 1 : height;

  // Camera
  double focal_length = 1.0f;
  double viewport_height = 2.0f;
  double viewport_width = viewport_height * ((double)width / height);
  vec3_t camera_center = vec3_create(0, 0, 0);

  vec3_t viewport_u = vec3_create(viewport_width, 0, 0);
  vec3_t viewport_v = vec3_create(0, -viewport_height, 0);

  vec3_t pixel_delta_u = vec3_div(viewport_u, width);
  vec3_t pixel_delta_v = vec3_div(viewport_v, height);

  vec3_t viewport_upper_left = vec3_sub(vec3_sub(vec3_sub(camera_center, vec3_create(0, 0, focal_length)), vec3_div(viewport_u, 2)), vec3_div(viewport_v, 2));
  vec3_t pixel_upper_left = vec3_add(viewport_upper_left, vec3_scale(vec3_add(pixel_delta_u, pixel_delta_v), 0.5f));

  // World
  hittable_list_t world = hittable_list_create(2);
  sphere_t main_sphere = sphere_create(vec3_create(0, 0, -1), 0.6f);
  sphere_t earth_sphere = sphere_create(vec3_create(0, -100.5, -1), 100.0f);
  hittable_list_add(&world, &main_sphere.base);
  hittable_list_add(&world, &earth_sphere.base);

  PPM img = ppm_create(width, height);
  for (unsigned int y = 0; y < height; y++) {
    for (unsigned int x = 0; x < width; x++) {
      vec3_t pixel_center = vec3_add(pixel_upper_left, vec3_add(vec3_scale(pixel_delta_u, x), vec3_scale(pixel_delta_v, y)));
      vec3_t ray_direction = vec3_sub(pixel_center, camera_center);

      ray_t r = {camera_center, ray_direction};

      color_t ray_col = ray_color(&r, &world);

      ppm_set(&img, x, y, ray_col);
    }
  }
  ppm_write(&img, "./test.ppm");
  printf("Done.\n");
}
