#include "utils.h"

#include <math.h>
#include <stdlib.h>
#include <time.h>

double rand_double(double min, double max) { return min + (max - min) * (rand() / (RAND_MAX + 1.0)); }

double linear_to_gamma(double linear) { return pow(linear, 1.0 / 2.2); }
