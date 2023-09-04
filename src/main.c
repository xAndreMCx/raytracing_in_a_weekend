#include "ppm.h"
#include <stdio.h>
#include "vec.h"

#define WIDTH 128
#define HEIGHT 128

int main(void) {
  PPM img = ppm_create(WIDTH, HEIGHT);
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      float red = (float)i / (WIDTH - 1);
      float blue = (float)j / (HEIGHT - 1);
      int green = 0;

      ppm_set(&img, j, i, (ppm_color){red * 255, green, blue * 255});
    }
  }
  ppm_write(&img, "./test.ppm");

  vec3 v = { 2, 3, 6 };
  v = vec3_normalised(v);
  vec3_print(v);
}
