#include "ppm.h"
#include <stdio.h>
#include <stdlib.h>

PPM ppm_create(unsigned int width, unsigned int height) {
  PPM img;
  img.width = width;
  img.height = height;
  img.image = malloc(sizeof(*img.image) * width * height * 3);
  return img;
}

void ppm_set(PPM *ppm, unsigned int x, unsigned int y, ppm_color color) {
  int index = ((y * ppm->width) + x) * 3;
  ppm->image[index + 0] = color.r;
  ppm->image[index + 1] = color.g;
  ppm->image[index + 2] = color.b;
}

void ppm_write(PPM *ppm, const char *path) {
  FILE *fp;
  fp = fopen(path, "w");

  fprintf(fp, "P3\n%d %d\n255\n", ppm->width, ppm->height);

  for (unsigned int y = 0; y < ppm->height; y++) {
    for (unsigned int x = 0; x < ppm->width; x++) {
      int index = (y * (ppm->width) + x) * 3;
      fprintf(fp, "%d %d %d\n", ppm->image[index], ppm->image[index + 1],
              ppm->image[index + 2]);
    }
  }

  fclose(fp);
}

void ppm_free(PPM *ppm) {
  if (ppm && ppm->image) {
    free(ppm->image);
  }
}