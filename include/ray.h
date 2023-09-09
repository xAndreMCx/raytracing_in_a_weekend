#pragma once
#include "vec.h"

typedef struct {
  vec3_t origin;
  vec3_t direction;
} ray_t;

vec3_t ray_point(ray_t r, double t);
color_t ray_color(ray_t r);
// double ray_hit_sphere(ray_t r, vec3_t center, double radius);