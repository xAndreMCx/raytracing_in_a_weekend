#include "ray.h"

#include <assert.h>

vec3_t ray_point(ray_t* ray, double t) {
  assert(ray);
  return vec3_add(vec3_scale(ray->direction, t), ray->origin);
}