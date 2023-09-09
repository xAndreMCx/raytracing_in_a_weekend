#include "vec.h"

#include <math.h>
#include <stdio.h>

void vec3_print(vec3_t a) { printf("vector = < %f, %f, %f >\n", a.x, a.y, a.z); }

vec3_t vec3_create(double x, double y, double z) { return (vec3_t){x, y, z}; }

vec3_t vec3_add(vec3_t a, vec3_t b) { return (vec3_t){a.x + b.x, a.y + b.y, a.z + b.z}; }

vec3_t vec3_sub(vec3_t a, vec3_t b) { return (vec3_t){a.x - b.x, a.y - b.y, a.z - b.z}; }

vec3_t vec3_scale(vec3_t a, double t) { return (vec3_t){a.x * t, a.y * t, a.z * t}; }

vec3_t vec3_div(vec3_t a, double t) { return vec3_scale(a, (1 / t)); }

double vec3_dot(vec3_t a, vec3_t b) { return a.x * b.x + a.y * b.y + a.z * b.z; }

vec3_t vec3_cross(vec3_t a, vec3_t b) { return (vec3_t){a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x}; }

vec3_t vec3_hadamard(vec3_t a, vec3_t b) { return (vec3_t){a.x * b.x, a.y * b.y, a.z * b.z}; }

double vec3_length(vec3_t a) { return sqrt(vec3_length_squared(a)); }

double vec3_length_squared(vec3_t a) { return (a.x * a.x) + (a.y * a.y) + (a.z * a.z); }

vec3_t vec3_normalised(vec3_t a) { return (vec3_t){a.x / vec3_length(a), a.y / vec3_length(a), a.z / vec3_length(a)}; }

color_t col_create(double r, double g, double b) { return (color_t){r, g, b}; }