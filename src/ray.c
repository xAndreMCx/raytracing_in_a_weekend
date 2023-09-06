#include "ray.h"

vec3 point_on_ray(ray r, double t) {
    return vec3_add(vec3_scale(r.direction, t), r.origin);
}