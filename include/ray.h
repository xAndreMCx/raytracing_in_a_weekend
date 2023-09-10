#pragma once

#include "vec.h"

typedef struct {
  vec3_t origin;
  vec3_t direction;
} ray_t;

vec3_t ray_point(ray_t* ray, double t);