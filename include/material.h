#pragma once
#include <stdbool.h>

// #include "hittable.h"
#include "ray.h"
#include "vec.h"

typedef struct material_t material_t;
typedef struct hit_record_s hit_record_t;

typedef bool (*material_scatter_fn)(ray_t*, hit_record_t*, color_t*, ray_t*, color_t);

material_t material_create(material_scatter_fn scatter, color_t albedo);
material_t material_create_lambertian(color_t albedo);
material_t material_create_metal(color_t albedo);

bool lambertian_scatter(ray_t* ray, hit_record_t* hit_record, color_t* attenuation, ray_t* scattered_ray, color_t albedo);
bool metal_scatter(ray_t* ray, hit_record_t* hit_record, color_t* attenuation, ray_t* scattered_ray, color_t albedo);