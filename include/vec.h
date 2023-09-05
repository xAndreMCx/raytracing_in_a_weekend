#pragma once

typedef union {
    double elements[3];
    struct {
      union {
        double x;
        unsigned char r;
      };
      union {
        double y;
        unsigned char g;
      };
      union {
        double z;
        unsigned char b;
      };
    };
} vec3;

typedef vec3 color_t;

void vec3_print(vec3 a);

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

color_t col_create(unsigned char r, unsigned char g, unsigned char b);