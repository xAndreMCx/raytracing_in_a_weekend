#pragma once

/**
 * @brief The value of pi.
 */
#define RT_PI 3.1415926535897932385

/**
 * @brief Converts degrees to radians.
 *
 * This macro converts an angle in degrees to radians.
 *
 * @param x The angle in degrees.
 * @return The angle in radians.
 */
#define DEG_TO_RAD(x) ((x) * (RT_PI / 180))

/**
 * @brief Converts radians to degrees.
 *
 * This macro converts an angle in radians to degrees.
 *
 * @param x The angle in radians.
 * @return The angle in degrees.
 */
#define RAD_TO_DEG(x) ((x) * (180 / RT_PI))

/**
 * @brief Generates a random double between min and max.
 *
 * This function generates a random double value in the range [min, max).
 *
 * @param min The minimum value.
 * @param max The maximum value.
 * @return A random double value between min and max.
 */
double rand_double(double min, double max);

/**
 * @brief Converts a linear color value to gamma-corrected value.
 *
 * @param linear The linear color value.
 * @return The gamma-corrected color value.
 */
double linear_to_gamma(double linear);