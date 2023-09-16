#pragma once

#include "hittable_list.h"
#include "ray.h"

typedef struct {
  unsigned int image_width;
  unsigned int image_height;
  double aspect_ratio;
  vec3_t center;
  vec3_t pixel_upper_left;
  vec3_t pixel_delta_u;
  vec3_t pixel_delta_v;
} camera_t;

camera_t camera_create(unsigned int image_width, double aspect_ratio);
void render(camera_t* camera, hittable_list_t* world, const char* filepath);
color_t ray_color(ray_t* ray, hittable_list_t* world);