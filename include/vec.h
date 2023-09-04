#pragma once

typedef union {
    double *elements[3];
    struct {
      double x;
      double y;
      double z;
    }
} vec3;

vec3 vec3_add(vec3 a, vec3 b);
vec3 vec3_sub(vec3 a, vec3 b);
vec3 vec3_scale(vec3 a, double t);
vec3 vec3_div(vec3 a, double t);
double vec3_dot(vec3 a, vec3 b);
vec3 vec3_cross(vec3 a, vec3 b);
vec3 vec3_hadamard(vec3 a, vec3 b);
double vec3_length(vec3 a);
double vec3_length_squared(vec3 a);
vec3 vec3_normalised(vec3 a);