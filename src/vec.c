#include "vec.h"

#include <math.h>
#include <stdio.h>

void vec3_print(vec3 a) {
    printf("vector = < %f, %f, %f >\n", a.x, a.y, a.z);
}

vec3 vec3_add(vec3 a, vec3 b) {
    return (vec3){a.x + b.x, a.y + b.y, a.z + b.z};
}

vec3 vec3_sub(vec3 a, vec3 b) {
    return (vec3){a.x-b.x, a.y-b.y, a.z-b.z};
}

vec3 vec3_scale(vec3 a, double t) {
    return (vec3){a.x*t, a.y*t, a.z*t};
}

vec3 vec3_div(vec3 a, double t) {
    return vec3_scale(a, (1/t));
}

double vec3_dot(vec3 a, vec3 b) {
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

vec3 vec3_cross(vec3 a, vec3 b){
    return (vec3){a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x};
}

vec3 vec3_hadamard(vec3 a, vec3 b) {
    return (vec3){a.x*b.x, a.y*b.y, a.z*b.z};
}

double vec3_length(vec3 a) {
    return sqrt(vec3_length_squared(a));
}

double vec3_length_squared(vec3 a) {
    return a.x * a.x + a.y * a.y + a.z * a.z;
}

vec3 vec3_normalised(vec3 a) {
    return (vec3){a.x/vec3_length(a), a.y/vec3_length(a), a.z/vec3_length(a)};
}

color_t col_create(unsigned char r, unsigned char g, unsigned char b) {
    return (color_t){.r=r, .g=g, .b=b};
}