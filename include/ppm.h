#pragma once
#include "vec.h"

/**
 * @struct PPM
 * @brief Represents a PPM image.
 *
 * This struct is used to represent a PPM image with a specified width and height.
 * The image data is stored as an array of unsigned char.
 */
typedef struct {
  unsigned int width;
  unsigned int height;
  unsigned char* image;
} PPM;

/**
 * @brief Creates a PPM image with the given width and height.
 *
 * This function allocates memory for a PPM image and initializes its width and height.
 *
 * @param width The width of the image.
 * @param height The height of the image.
 * @return A PPM image with the specified width and height.
 */
PPM ppm_create(unsigned int width, unsigned int height);

/**
 * @brief Sets the color of a pixel in the PPM image.
 *
 * This function sets the color of the pixel at the specified (x, y) coordinates in the PPM image.
 *
 * @note The origin of the PPM image is at (0, 0) which is at the top left.
 *
 * @param ppm The PPM image.
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 * @param color The color to set the pixel to.
 */
void ppm_set(PPM* ppm, unsigned int x, unsigned int y, color_t color);

/**
 * @brief Writes the PPM image to a file.
 *
 * This function writes the PPM image data to a .ppm file at the specified path.
 *
 * @param ppm The PPM image.
 * @param path The path to the file where it will be saved.
 */
void ppm_write(PPM* ppm, const char* path);

/**
 * @brief Frees the memory used by the PPM image.
 *
 * This function frees the memory allocated for the PPM image data.
 *
 * @param ppm The PPM image.
 */
void ppm_free(PPM* ppm);