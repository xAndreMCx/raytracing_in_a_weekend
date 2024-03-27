#include "material.h"

#include <assert.h>
#include <stdlib.h>

// #include "hittable.h
typedef struct hit_record_r hit_record_t;

struct material_t {
  material_scatter_fn scatter;
  color_t albedo;
};

material_t material_create(material_scatter_fn scatter, color_t albedo) {
  material_t result = {.scatter = scatter, .albedo = albedo};
  return result;
}

material_t material_create_lambertian(color_t albedo) { return material_create(lambertian_scatter, albedo); }

material_t material_create_metal(color_t albedo) { return material_create(metal_scatter, albedo); }

bool lambertian_scatter(ray_t* ray, hit_record_t* hit_record, color_t* attenuation, ray_t* scattered_ray, color_t albedo) {
  assert(ray);
  assert(hit_record);
  assert(attenuation);
  assert(scattered_ray);

  vec3_t scatter_direction = vec3_add(hit_record->normal, vec3_create_random_unit());
  if (vec3_near_zero(scatter_direction)) {
    scatter_direction = hit_record->normal;
  }

  *scattered_ray = (ray_t){hit_record->point, scatter_direction};
  *attenuation = albedo;
  return true;
}

bool metal_scatter(ray_t* ray, hit_record_t* hit_record, color_t* attenuation, ray_t* scattered_ray, color_t albedo) {
  assert(ray);
  assert(hit_record);
  assert(attenuation);
  assert(scattered_ray);

  vec3_t reflected = vec3_reflect(vec3_normalised(ray->direction), hit_record->normal);
  *scattered_ray = (ray_t){hit_record->point, reflected};
  *attenuation = albedo;
  // return vec3_dot(scattered_ray->direction, hit_record->normal) > 0;
  return true;
}