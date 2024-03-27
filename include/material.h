#pragma once
#include <stdbool.h>

#include "hittable.h"
#include "ray.h"
#include "vec.h"

typedef enum { MATERIAL_UNKOWN = -1, MATERIAL_LAMBERTIAN = 0, MATERIAL_METAL = 2 } material_type_t;

typedef struct {
  material_type_t type;
} material_t;

bool material_scatter(material_t* material, ray_t* ray, hit_record_t* hit_record, color_t* attenuation, ray_t* scattered_ray);

typedef struct {
  material_t base;
  color_t albedo;
} lambertian_t;

lambertian_t lambertian_create(color_t albedo);
bool lambertian_scatter(lambertian_t* material, ray_t* ray, hit_record_t* hit_record, color_t* attenuation, ray_t* scattered_ray);

typedef struct {
  material_t base;
  color_t albedo;
} metal_t;

metal_t metal_create(color_t albedo);
bool metal_scatter(metal_t* material, ray_t* ray, hit_record_t* hit_record, color_t* attenuation, ray_t* scattered_ray);