#include <stdio.h>

#include "ppm.h"
#include "ray.h"
#include "vec.h"

int main(void) {
  double aspect_ratio = 16.f / 9.0f;
  unsigned int width = 400;
  unsigned int height = width / aspect_ratio;
  height = (height < 1) ? 1 : height;

  double focal_length = 1.0f;
  double viewport_height = 2.0f;
  double viewport_width = viewport_height * ((double)width / height);
  vec3 camera_center = vec3_create(0, 0, 0);

  vec3 viewport_u = vec3_create(viewport_width, 0, 0);
  vec3 viewport_v = vec3_create(0, -viewport_height, 0);

  vec3 pixel_delta_u = vec3_div(viewport_u, width);
  vec3 pixel_delta_v = vec3_div(viewport_v, height);

  // camera center - vec3(0, 0, focal_length) - viewport_u/2 - viewport_v/2
  vec3 viewport_upper_left = vec3_sub(vec3_sub(vec3_sub(camera_center, vec3_create(0, 0, focal_length)), vec3_div(viewport_u, 2)), vec3_div(viewport_v, 2));
  vec3 pixel_upper_left = vec3_add(viewport_upper_left, vec3_scale(vec3_add(pixel_delta_u, pixel_delta_v), 0.5f));

  PPM img = ppm_create(width, height);
  for (unsigned int y = 0; y < height; y++) {
    for (unsigned int x = 0; x < width; x++) {
      vec3 pixel_center = vec3_add(pixel_upper_left, vec3_add(vec3_scale(pixel_delta_u, x), vec3_scale(pixel_delta_v, y)));
      vec3 ray_direction = vec3_sub(pixel_center, camera_center);

      ray_t r = {camera_center, ray_direction};

      color_t ray_col = ray_color(r);

      ppm_set(&img, x, y, ray_col);
    }
  }
  ppm_write(&img, "./test.ppm");
  printf("Done.\n");
}
