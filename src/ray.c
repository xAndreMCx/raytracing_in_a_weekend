#include "ray.h"

#include <math.h>

#include "hittable.h"
#include "sphere.h"

vec3_t ray_point(ray_t r, double t) { return vec3_add(vec3_scale(r.direction, t), r.origin); }

color_t ray_color(ray_t r) {
  vec3_t center = vec3_create(0, 0, -1);
  sphere_t sphere = sphere_create(center, 0.5f);

  hit_record_t hit_record;
  if (hittable_hit(&sphere, &r, 0, INFINITY, &hit_record)) {
    return vec3_scale(vec3_add(hit_record.normal, vec3_create(1, 1, 1)), 0.5);
  }

  vec3_t unit_vec = vec3_normalised(r.direction);
  double a = (unit_vec.y + 1.00f) * 0.5f;
  return vec3_add(vec3_scale(col_create(1.0f, 1.0f, 1.0f), 1.00f - a), vec3_scale(col_create(0.5f, 0.7f, 1.0f), a));
}