#include "material.h"

bool material_scatter(material_t* material, ray_t* ray, hit_record_t* hit_record, color_t* attenuation, ray_t* scattered_ray) {
  switch (material->type) {
    case MATERIAL_LAMBERTIAN:
      return lambertian_scatter((lambertian_t*)material, ray, hit_record, attenuation, scattered_ray);

    case MATERIAL_METAL:
      return metal_scatter((metal_t*)material, ray, hit_record, attenuation, scattered_ray);

    default:
      return false;
  }
}

lambertian_t lambertian_create(color_t albedo) { return (lambertian_t){{MATERIAL_LAMBERTIAN}, albedo}; }

bool lambertian_scatter(lambertian_t* material, ray_t* ray, hit_record_t* hit_record, color_t* attenuation, ray_t* scattered_ray) {
  vec3_t scatter_direction = vec3_add(hit_record->normal, vec3_create_random_unit());
  if (vec3_near_zero(scatter_direction)) {
    scatter_direction = hit_record->normal;
  }
  *scattered_ray = (ray_t){hit_record->point, scatter_direction};
  *attenuation = material->albedo;
  return true;
}

metal_t metal_create(color_t albedo, double fuzz) {
  fuzz = (fuzz < 1) ? fuzz : 1;
  metal_t result = {{MATERIAL_METAL}, albedo, fuzz};
  return result;
}

bool metal_scatter(metal_t* material, ray_t* ray, hit_record_t* hit_record, color_t* attenuation, ray_t* scattered_ray) {
  vec3_t reflected = vec3_reflect(vec3_normalised(ray->direction), hit_record->normal);
  reflected = vec3_add(reflected, vec3_scale(vec3_create_random_unit(), material->fuzz));
  *scattered_ray = (ray_t){hit_record->point, reflected};
  *attenuation = material->albedo;
  return vec3_dot(scattered_ray->direction, hit_record->normal) > 0;
}