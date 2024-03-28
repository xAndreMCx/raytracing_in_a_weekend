#include <assert.h>
#include <math.h>
#include <stdio.h>

#include "camera.h"
#include "hittable_list.h"
#include "material.h"
#include "sphere.h"
#include "utils.h"
#include "vec.h"

int main(void) {
  // Camera
  double aspect_ratio = 16.0 / 9.0;
  unsigned int width = 400u;
  camera_t camera = camera_create(width, aspect_ratio, vec3_create(-2, 2, 1), vec3_create(0, 0, -1), vec3_create(0, 1, 0), 20.0);

  lambertian_t material_ground = lambertian_create(col_create(0.8, 0.8, 0.0));
  lambertian_t material_center = lambertian_create(col_create(0.1, 0.2, 0.5));
  dielectric_t material_left = dielectric_create(2.5);
  metal_t material_right = metal_create(col_create(0.8, 0.6, 0.2), 0.0);

  sphere_t sphere_ground = sphere_create(vec3_create(0, -100.5, -1), 100, &material_ground.base);
  sphere_t sphere_center = sphere_create(vec3_create(0, 0, -1), 0.5, &material_center.base);
  sphere_t sphere_left = sphere_create(vec3_create(-1, 0, -1), 0.5, &material_left.base);
  sphere_t sphere_inner = sphere_create(vec3_create(-1, 0, -1), -0.4, &material_left.base);
  sphere_t sphere_right = sphere_create(vec3_create(1, 0, -1), 0.5, &material_right.base);

  hittable_list_t world = hittable_list_create(4);
  hittable_list_add(&world, &sphere_ground.base);
  hittable_list_add(&world, &sphere_center.base);
  hittable_list_add(&world, &sphere_left.base);
  hittable_list_add(&world, &sphere_inner.base);
  hittable_list_add(&world, &sphere_right.base);

  render(&camera, &world, "./test.ppm");

  hittable_list_free(&world);

  printf("Done.\n");

  return 0;
}
