#include "ray.h"

#include "math.h"

vec3 ray_point(ray_t r, double t) { return vec3_add(vec3_scale(r.direction, t), r.origin); }

color_t ray_color(ray_t r) {
  vec3 center = vec3_create(0, 0, -1);
  double t = ray_hit_sphere(r, center, 0.5);
  if (t > 0) {
    vec3 normal = vec3_normalised(vec3_sub(ray_point(r, t), center));
    return vec3_scale(col_create(normal.x + 1, normal.y + 1, normal.z + 1), 0.5f);
  }

  vec3 unit_vec = vec3_normalised(r.direction);
  double a = (unit_vec.y + 1.00f) * 0.5f;
  return vec3_add(vec3_scale(col_create(1.0f, 1.0f, 1.0f), 1.00f - a), vec3_scale(col_create(0.5f, 0.7f, 1.0f), a));
}

double ray_hit_sphere(ray_t r, vec3 center, double radius) {
  vec3 oc = vec3_sub(r.origin, center);
  double a = vec3_length_squared(r.direction);
  double half_b = vec3_dot(oc, r.direction);
  double c = vec3_length_squared(oc) - (radius * radius);
  double discriminant = (half_b * half_b) - (a * c);
  if (discriminant < 0) {
    return -1.0f;
  }

  return (-half_b - sqrt(discriminant) / a);
}