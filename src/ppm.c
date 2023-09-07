#include "ppm.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

static void ppm_abort(PPM* ppm, const char* fmt, ...);

PPM ppm_create(unsigned int width, unsigned int height) {
  PPM img;
  img.width = width;
  img.height = height;
  img.image = malloc(sizeof(*img.image) * width * height * 3);
  return img;
}

void ppm_set(PPM* ppm, unsigned int x, unsigned int y, color_t color) {
  if (!ppm) {
    ppm_abort(ppm, "Passed NULL to ppm_set()\n");
  }

  if (x >= ppm->width || y >= ppm->height) {
    ppm_abort(ppm, "Index is out of bounds in ppm_set(%d, %d)\n", x, y);
  }

  int index = ((y * ppm->width) + x) * 3;
  ppm->image[index + 0] = color.r * 255;
  ppm->image[index + 1] = color.g * 255;
  ppm->image[index + 2] = color.b * 255;
}

void ppm_write(PPM* ppm, const char* path) {
  if (!ppm) {
    ppm_abort(ppm, "Passed NULL to ppm_write()\n");
  }

  FILE* fp;
  fp = fopen(path, "w");

  if (!fp) {
    ppm_abort(ppm, "Could not open file %s for writing\n", path);
  }

  fprintf(fp, "P3\n%d %d\n255\n", ppm->width, ppm->height);

  for (unsigned int y = 0; y < ppm->height; y++) {
    for (unsigned int x = 0; x < ppm->width; x++) {
      int index = (y * (ppm->width) + x) * 3;
      fprintf(fp, "%d %d %d\n", ppm->image[index], ppm->image[index + 1], ppm->image[index + 2]);
    }
  }

  fclose(fp);
}

static void ppm_abort(PPM* ppm, const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  vfprintf(stderr, fmt, args);
  va_end(args);

  fprintf(stderr, "Aborting\n");
  ppm_free(ppm);
  exit(EXIT_FAILURE);
}

void ppm_free(PPM* ppm) {
  if (ppm && ppm->image) {
    free(ppm->image);
  }
}