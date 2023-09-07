#pragma once
#include "vec.h"

typedef struct {
  vec3 origin;
  vec3 direction;
} ray_t;

vec3 ray_point(ray_t r, double t);
color_t ray_color(ray_t r);