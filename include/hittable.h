#pragma once

#include <stdbool.h>

#include "interval.h"
#include "ray.h"
#include "vec.h"

typedef struct {
  vec3_t point;
  vec3_t normal;
  void* material;
  double t;
  bool front_facing;
} hit_record_t;

typedef enum { HITTABLE_UNKOWN = -1, HITTABLE_SPHERE = 0 } hittable_type_t;

typedef struct {
  hittable_type_t type;
} hittable_t;

bool hittable_hit(hittable_t* hittable, ray_t* ray, interval_t* interval, hit_record_t* hit_record);
void set_face_normal(hit_record_t* hit_record, ray_t* ray, vec3_t* outward_normal);