#pragma once

#include <stdbool.h>

#include "hittable.h"
#include "interval.h"
#include "ray.h"

typedef struct {
  hittable_t** hittables;
  unsigned int length;
  unsigned int capacity;
} hittable_list_t;

hittable_list_t hittable_list_create(unsigned int capacity);
void hittable_list_add(hittable_list_t* list, hittable_t* hittable);
void hittable_list_clear(hittable_list_t* list);
void hittable_list_free(hittable_list_t* list);
bool hittable_list_hit(hittable_list_t* list, ray_t* ray, interval_t* interval, hit_record_t* hit_record);