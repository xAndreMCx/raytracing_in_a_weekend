#include "interval.h"

#include <math.h>

interval_t interval_create(double min, double max) {
  interval_t result = {.min = min, .max = max};
  return result;
}

bool interval_contains(interval_t* interval, double x) { return (interval->min <= x && x <= interval->max); }
bool interval_surrounds(interval_t* interval, double x) { return (interval->min < x && x < interval->max); }
double interval_clamp(interval_t* interval, double x) {
  if (x < interval->min) {
    return interval->min;
  }
  if (x > interval->max) {
    return interval->max;
  }
  return x;
}