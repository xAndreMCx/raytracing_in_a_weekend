#pragma once

#include "hittable.h"
#include "vec.h"

typedef struct {
  hittable_t base;
  vec3_t center;
  double radius;
} sphere_t;

sphere_t sphere_create(vec3_t center, double radius);
bool sphere_hit(sphere_t* sphere, ray_t* ray, double min_t, double max_t, hit_record_t* hit_record);