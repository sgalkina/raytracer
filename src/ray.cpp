#include "ray.h"
#include "vector.h"

ray::ray(double_vector const &point, unit_vector const &ray_vector) {
  point_start = point;
  direction = ray_vector;
}

ray ray::from_point_to_direction(double_vector const &point,
                                 double_vector const &ray_vector) {
  return ray(point, ray_vector.get_unit_vector());
}

ray ray::from_point_to_point(double_vector const &point_start,
                             double_vector const &point_end) {
  double_vector point = point_start;
  double_vector direction = point_end - point_start;
  return from_point_to_direction(point, direction);
}

double_vector ray::apply(double t) {
  double_vector vector_end = direction * t;
  return point_start + vector_end;
}
