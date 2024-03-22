#include "vec.h"

#include <math.h>
#include <stdio.h>

void vec3_print(vec3_t a) { printf("vector = < %f, %f, %f >\n", a.x, a.y, a.z); }

vec3_t vec3_create(double x, double y, double z) {
  vec3_t result = {.x = x, .y = y, .z = z};
  return result;
}

vec3_t vec3_add(vec3_t a, vec3_t b) {
  vec3_t result = {.x = (a.x + b.x), .y = (a.y + b.y), .z = (a.z + b.z)};
  return result;
}

vec3_t vec3_sub(vec3_t a, vec3_t b) {
  vec3_t result = {.x = (a.x - b.x), .y = (a.y - b.y), .z = (a.z - b.z)};
  return result;
}

vec3_t vec3_negate(vec3_t a) {
  vec3_t result = {.x = -a.x, .y = -a.y, .z = -a.z};
  return result;
}

vec3_t vec3_scale(vec3_t a, double t) {
  vec3_t result = {.x = (a.x * t), .y = (a.y * t), .z = (a.z * t)};
  return result;
}
// TODO: check div by zero
vec3_t vec3_div(vec3_t a, double t) { return vec3_scale(a, (1 / t)); }

double vec3_dot(vec3_t a, vec3_t b) { return a.x * b.x + a.y * b.y + a.z * b.z; }

vec3_t vec3_cross(vec3_t a, vec3_t b) {
  vec3_t result = {.x = (a.y * b.z - a.z * b.y), .y = (a.z * b.x - a.x * b.z), .z = (a.x * b.y - a.y * b.x)};
  return result;
}

vec3_t vec3_hadamard(vec3_t a, vec3_t b) {
  vec3_t result = {.x = (a.x * b.x), .y = (a.y * b.y), .z = (a.z * b.z)};
  return result;
}

double vec3_length(vec3_t a) { return sqrt(vec3_length_squared(a)); }

double vec3_length_squared(vec3_t a) { return (a.x * a.x) + (a.y * a.y) + (a.z * a.z); }

// TODO: check div by zero
vec3_t vec3_normalised(vec3_t a) {
  vec3_t result = {.x = (a.x / vec3_length(a)), .y = (a.y / vec3_length(a)), .z = (a.z / vec3_length(a))};
  return result;
}

color_t col_create(double r, double g, double b) {
  vec3_t color = {.r = r, .g = g, .b = b};
  return color;
}