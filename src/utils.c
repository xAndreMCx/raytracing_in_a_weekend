#include "utils.h"

#include <stdlib.h>

double rand_double(double min, double max) { return min + (max - min) * (rand() / (RAND_MAX + 1.0)); }