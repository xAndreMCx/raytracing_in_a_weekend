#pragma once
#include "vec.h"

typedef struct {
  unsigned int width;
  unsigned int height;
  unsigned char* image;
} PPM;

typedef struct {
  unsigned char r;
  unsigned char g;
  unsigned char b;
} ppm_color;

PPM ppm_create(unsigned int width, unsigned int height);
void ppm_set(PPM* ppm, unsigned int x, unsigned int y, color_t color);
void ppm_write(PPM* ppm, const char* path);
void ppm_free(PPM* ppm);