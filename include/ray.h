#pragma once
#include "vec.h"

typedef struct {
  vec3 origin;
  vec3 direction;
} ray;

vec3 point_on_ray(ray r, double t);