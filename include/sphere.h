#pragma once

#include "hittable.h"
#include "interval.h"
#include "material.h"
#include "vec.h"

typedef struct {
  hittable_t base;
  vec3_t center;
  double radius;
  material_t* material;
} sphere_t;

sphere_t sphere_create(vec3_t center, double radius, material_t* material);
bool sphere_hit(sphere_t* sphere, ray_t* ray, interval_t* interval, hit_record_t* hit_record);