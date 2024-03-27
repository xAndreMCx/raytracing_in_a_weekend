#include <assert.h>
#include <math.h>
#include <stdio.h>

#include "camera.h"
#include "hittable_list.h"
#include "material.h"
#include "ppm.h"
#include "ray.h"
#include "sphere.h"
#include "vec.h"

int main(void) {
  // Camera
  double aspect_ratio = 16.0 / 9.0;
  unsigned int width = 400u;
  camera_t camera = camera_create(width, aspect_ratio);

  lambertian_t material_ground = lambertian_create(col_create(0.8, 0.8, 0.0));
  lambertian_t material_center = lambertian_create(col_create(0.7, 0.3, 0.3));
  metal_t material_left = metal_create(col_create(0.8, 0.8, 0.8), 0.3);
  metal_t material_right = metal_create(col_create(0.8, 0.6, 0.2), 1.0);

  // World
  hittable_list_t world = hittable_list_create(4);
  sphere_t earth_sphere = sphere_create(vec3_create(0, -100.5, -1), 100.0, &material_ground.base);
  sphere_t main_sphere = sphere_create(vec3_create(0, 0, -1), 0.5, &material_center.base);
  sphere_t left_sphere = sphere_create(vec3_create(-1, 0, -1), 0.5, &material_left.base);
  sphere_t right_sphere = sphere_create(vec3_create(1, 0, -1), 0.5, &material_right.base);

  hittable_list_add(&world, &main_sphere.base);
  hittable_list_add(&world, &left_sphere.base);
  hittable_list_add(&world, &right_sphere.base);
  hittable_list_add(&world, &earth_sphere.base);

  render(&camera, &world, "./test.ppm");

  hittable_list_free(&world);

  printf("Done.\n");

  return 0;
}
