#include "sphere.h"

#include "math.h"

sphere_t sphere_create(vec3_t center, double radius) {
  sphere_t result = {HITTABLE_SPHERE, center, radius};
  return result;
}

bool sphere_hit(sphere_t* sphere, ray_t* ray, double min_t, double max_t, hit_record_t* hit_record) {
  vec3_t oc = vec3_sub(ray->origin, sphere->center);
  double a = vec3_length_squared(ray->direction);
  double half_b = vec3_dot(oc, ray->direction);
  double c = vec3_length_squared(oc) - (sphere->radius * sphere->radius);
  double discriminant = (half_b * half_b) - (a * c);

  if (discriminant < 0) {
    return false;
  }

  double sqrt_discriminant = sqrt(discriminant);

  // Find the nearest root that's in an acceptable range
  double root = (-half_b - sqrt_discriminant) / a;
  if (root <= min_t || root >= max_t) {
    root = (-half_b + sqrt_discriminant) / a;
    if (root <= min_t || root >= max_t) {
      return false;
    }
  }

  hit_record->t = root;
  hit_record->point = ray_point(*ray, root);
  hit_record->normal = vec3_scale(vec3_sub(oc, sphere->center), sphere->radius);

  return true;
}
