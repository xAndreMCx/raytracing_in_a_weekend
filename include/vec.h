#pragma once
#include <stdbool.h>

typedef union {
  double elements[3];
  struct {
    union {
      double x;
      double r;
    };
    union {
      double y;
      double g;
    };
    union {
      double z;
      double b;
    };
  };
} vec3_t;

typedef vec3_t color_t;

/**
 * @brief Prints a vec3_t vector to stdout in the format: vector = < x, y, z >
 *
 * @param a The vector to be printed.
 */
void vec3_print(vec3_t a);

/**
 * @brief Creates a vec3_t vector with the given components.
 *
 * @param x The x component.
 * @param y The y component.
 * @param z The z component.
 * @return A vec3_t vector with the specified components.
 */
vec3_t vec3_create(double x, double y, double z);

/**
 * @brief Adds two vec3_t vectors component-wise.
 *
 * @param a The first vector.
 * @param b The second vector.
 * @return The result of adding the two vectors.
 */
vec3_t vec3_add(vec3_t a, vec3_t b);

/**
 * @brief Subtracts the second vec3_t vector from the first component-wise.
 *
 * @param a The first vector.
 * @param b The second vector.
 * @return The result of subtracting the second vector from the first.
 */
vec3_t vec3_sub(vec3_t a, vec3_t b);

/**
 * @brief Negates each component of the vec3_t vector.
 *
 * @param a The vector to negate.
 * @return The negated vector.
 */
vec3_t vec3_negate(vec3_t a);

/**
 * @brief Scales each component of the vec3_t vector by a scalar.
 *
 * @param a The vector to scale.
 * @param t The scalar to scale by.
 * @return The scaled vector.
 */
vec3_t vec3_scale(vec3_t a, double t);

/**
 * @brief Divides each component of the vec3_t vector by a scalar.
 *
 * @param a The vector to divide.
 * @param t The scalar to divide by.
 * @return The divided vector.
 */
vec3_t vec3_div(vec3_t a, double t);

/**
 * @brief Computes the dot product of two vec3_t vectors.
 *
 * @param a The first vector.
 * @param b The second vector.
 * @return The dot product of the two vectors.
 */
double vec3_dot(vec3_t a, vec3_t b);

/**
 * @brief Computes the cross product of two vec3_t vectors.
 *
 * @param a The first vector.
 * @param b The second vector.
 * @return The cross product of the two vectors.
 */
vec3_t vec3_cross(vec3_t a, vec3_t b);

/**
 * @brief Computes the Hadamard product (component-wise multiplication) of two vec3_t vectors.
 *
 * @param a The first vector.
 * @param b The second vector.
 * @return The Hadamard product of the two vectors.
 */
vec3_t vec3_hadamard(vec3_t a, vec3_t b);

/**
 * @brief Computes the length (magnitude) of the vec3_t vector.
 *
 * @param a The vector.
 * @return The length of the vector.
 */
double vec3_length(vec3_t a);

/**
 * @brief Computes the squared length of the vec3_t vector.
 *
 * @param a The vector.
 * @return The squared length of the vector.
 */
double vec3_length_squared(vec3_t a);

/**
 * @brief Normalizes the vec3_t vector.
 *
 * @param a The vector to normalize.
 * @return The normalized vector.
 */
vec3_t vec3_normalised(vec3_t a);

/**
 * @brief Creates a vec3_t vector with random components in the given range.
 *
 * @param min The minimum value for each component.
 * @param max The maximum value for each component.
 * @return A vec3_t vector with random components.
 */
vec3_t vec3_create_random(double min, double max);

/**
 * @brief Creates a vec3_t vector with random components in the unit sphere.
 *
 * @return A vec3_t vector with random components in the unit sphere.
 */
vec3_t vec3_create_random_unit();

/**
 * @brief Applies a function to each component of the vec3_t vector.
 *
 * @param a The vector.
 * @param fn The function to apply to each component.
 * @return The vector with the function applied to each component.
 */
vec3_t vec3_map(vec3_t a, double (*fn)(double));

/**
 * @brief Checks if the vec3_t vector is near zero (all components are close to zero).
 *
 * @param a The vector.
 * @return True if the vector is near zero, false otherwise.
 */
bool vec3_near_zero(vec3_t a);

/**
 * @brief Reflects the vec3_t vector about a normal vector.
 *
 * @param v The vector to reflect.
 * @param normal The normal vector to reflect about.
 * @return The reflected vector.
 */
vec3_t vec3_reflect(vec3_t v, vec3_t normal);

/**
 * @brief Refracts the vec3_t vector through a normal vector using Snell's law.
 *
 * @param uv The incident vector.
 * @param normal The normal vector.
 * @param etai_over_etat The ratio of indices of refraction.
 * @return The refracted vector.
 */
vec3_t vec3_refract(vec3_t uv, vec3_t normal, double etai_over_etat);

/**
 * @brief Creates a vec3_t vector with random components in the unit disk.
 *
 * @return A vec3_t vector with random components in the unit disk.
 */
vec3_t vec3_random_in_unit_disk();

/**
 * @brief Creates a color_t color with the given components.
 *
 * @param r The red component. (0.0 - 1.0)
 * @param g The green component. (0.0 - 1.0)
 * @param b The blue component. (0.0 - 1.0)
 * @return A color_t color with the specified components.
 */
color_t col_create(double r, double g, double b);