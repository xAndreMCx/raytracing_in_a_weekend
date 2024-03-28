#pragma once
#include <stdbool.h>

typedef union {
  double elements[3];
  struct {
    union {
      double x;
      double r;
    };
    union {
      double y;
      double g;
    };
    union {
      double z;
      double b;
    };
  };
} vec3_t;

typedef vec3_t color_t;

void vec3_print(vec3_t a);
vec3_t vec3_create(double x, double y, double z);
vec3_t vec3_add(vec3_t a, vec3_t b);
vec3_t vec3_sub(vec3_t a, vec3_t b);
vec3_t vec3_negate(vec3_t a);
vec3_t vec3_scale(vec3_t a, double t);
vec3_t vec3_div(vec3_t a, double t);
double vec3_dot(vec3_t a, vec3_t b);
vec3_t vec3_cross(vec3_t a, vec3_t b);
vec3_t vec3_hadamard(vec3_t a, vec3_t b);
double vec3_length(vec3_t a);
double vec3_length_squared(vec3_t a);
vec3_t vec3_normalised(vec3_t a);
vec3_t vec3_create_random(double min, double max);
vec3_t vec3_create_random_unit();
vec3_t vec3_map(vec3_t a, double (*fn)(double));
bool vec3_near_zero(vec3_t a);
vec3_t vec3_reflect(vec3_t v, vec3_t normal);
vec3_t vec3_refract(vec3_t uv, vec3_t normal, double etai_over_etat);

color_t col_create(double r, double g, double b);