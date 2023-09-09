#pragma once

#include <stdbool.h>

#include "ray.h"
#include "vec.h"

typedef struct {
  vec3_t point;
  vec3_t normal;
  double t;
} hit_record_t;

typedef enum { HITTABLE_UNKOWN = -1, HITTABLE_SPHERE = 0 } hittable_type_t;

typedef struct {
  hittable_type_t type;
} hittable_t;

bool hittable_hit(hittable_t* hittable, ray_t* ray, double min_t, double max_t, hit_record_t* hit_record);