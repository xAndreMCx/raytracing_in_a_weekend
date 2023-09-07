#include "ray.h"

vec3 ray_point(ray_t r, double t) { return vec3_add(vec3_scale(r.direction, t), r.origin); }

color_t ray_color(ray_t r) {
  vec3 unit_vec = vec3_normalised(r.direction);
  double a = (unit_vec.y + 1.00f) * 0.5f;
  return vec3_add(vec3_scale(col_create(1.0f, 1.0f, 1.0f), 1.00f - a), vec3_scale(col_create(0.5f, 0.7f, 1.0f), a));
}