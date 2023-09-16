#include <assert.h>
#include <math.h>
#include <stdio.h>

#include "camera.h"
#include "hittable_list.h"
#include "ppm.h"
#include "ray.h"
#include "sphere.h"
#include "vec.h"

int main(void) {
  // Camera
  double aspect_ratio = 16.f / 9.0f;
  unsigned int width = 400;
  camera_t camera = camera_create(width, aspect_ratio);

  // World
  hittable_list_t world = hittable_list_create(2);
  sphere_t main_sphere = sphere_create(vec3_create(0, 0, -1), 0.6f);
  sphere_t earth_sphere = sphere_create(vec3_create(0, -100.5, -1), 100.0f);
  hittable_list_add(&world, &main_sphere.base);
  hittable_list_add(&world, &earth_sphere.base);

  // PPM img = ppm_create(width, height);
  // for (unsigned int y = 0; y < height; y++) {
  //   for (unsigned int x = 0; x < width; x++) {
  //     vec3_t pixel_center = vec3_add(pixel_upper_left, vec3_add(vec3_scale(pixel_delta_u, x), vec3_scale(pixel_delta_v, y)));
  //     vec3_t ray_direction = vec3_sub(pixel_center, camera_center);

  //     ray_t r = {camera_center, ray_direction};

  //     color_t ray_col = ray_color(&r, &world);

  //     ppm_set(&img, x, y, ray_col);
  //   }
  // }
  // ppm_write(&img, "./test.ppm");
  render(&camera, &world, "./test.ppm");
  printf("Done.\n");
}
