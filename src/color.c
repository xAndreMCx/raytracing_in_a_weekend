#include "color.h"

#include <assert.h>

#include "hittable.h"
color_t ray_color(ray_t* ray, unsigned int depth, hittable_list_t* world) {
  assert(ray);
  assert(world);

  if (depth <= 0) {
    return col_create(0, 0, 0);
  }

  hit_record_t hit_record;
  if (hittable_list_hit(world, ray, &(interval_t){.min = 0.0001, .max = INFINITY}, hit_record)) {
    ray_t scattered;
    color_t attenuation;
    if (hit_rec(ray, hit_record, &attenuation, &scattered, hit_record->material.albedo)) {
      return vec3_hadamard(ray_color(&scattered, depth - 1, world), attenuation);
    }
    return vec3_create(0, 0, 0);
    // vec3_t direction = vec3_add(hit_record.normal, vec3_create_random_unit());
    // return vec3_scale(ray_color(&(ray_t){hit_record.point, direction}, depth - 1, world), 0.5);
  }

  // Background
  vec3_t unit_vec = vec3_normalised(ray->direction);
  double a = (unit_vec.y + 1.00) * 0.5;
  return vec3_add(vec3_scale(col_create(1.0, 1.0, 1.0), 1.00 - a), vec3_scale(col_create(0.5, 0.7, 1.0), a));
}
