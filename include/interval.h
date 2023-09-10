#pragma once

#include <math.h>
#include <stdbool.h>

typedef struct {
  double min;
  double max;
} interval_t;

interval_t interval_create(double min, double max);
bool interval_contains(interval_t* interval, double x);
bool interval_surrounds(interval_t* interval, double x);

#define EMPTY_INTERVAL ((interval_t){.min = INFINITY, .max = -INFINITY})
#define UNIVERSE_INTERVAL ((interval_t){.min = -INFINITY, .max = INFINITY})