#pragma once

#include "hittable.h"
#include "interval.h"
#include "vec.h"

typedef struct {
  hittable_t base;
  vec3_t center;
  double radius;
} sphere_t;

sphere_t sphere_create(vec3_t center, double radius);
bool sphere_hit(sphere_t* sphere, ray_t* ray, interval_t* interval, hit_record_t* hit_record);