#pragma once

#include "hittable_list.h"
#include "ray.h"
#include "vec.h"

color_t ray_color(ray_t* ray, unsigned int depth, hittable_list_t* world);