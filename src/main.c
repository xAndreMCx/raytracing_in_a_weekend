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

  render(&camera, &world, "./test.ppm");
  printf("Done.\n");
}
