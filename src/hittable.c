#include "hittable.h"

#include "sphere.h"

bool hittable_hit(hittable_t* hittable, ray_t* ray, double min_t, double max_t, hit_record_t* hit_record) {
  switch (hittable->type) {
    case HITTABLE_SPHERE:
      return sphere_hit((sphere_t*)hittable, ray, min_t, max_t, hit_record);

    default:

      return 0;
  }
}