#include "ray.h"
#include "scene.h"
#include "shapes.h"
#include "vector.h"

ray::ray(double_vector point, unit_vector ray_vector) {
  point_start = point;
  direction = ray_vector;
}

ray ray::from_point_to_direction(double_vector point,
                                 double_vector ray_vector) {
  return ray(point, ray_vector.get_unit_vector());
}

ray ray::from_point_to_point(double_vector point_start,
                             double_vector point_end) {
  double_vector point = point_start;
  double_vector direction = point_end - point_start;
  return from_point_to_direction(point, direction);
}

double_vector ray::apply(double t) {
  double_vector vector_end = direction * t;
  return point_start + vector_end;
}
