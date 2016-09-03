#include "ray.h"
#include "vector.h"

ray::ray(double_vector const &point, unit_vector const &ray_vector)
    : direction_(ray_vector), point_start_(point) {}

ray ray::from_point_to_direction(double_vector const &point,
                                 double_vector const &ray_vector) {
  return ray(point, ray_vector.get_unit_vector());
}

ray ray::from_point_to_point(double_vector const &point_start,
                             double_vector const &point_end) {
  return from_point_to_direction(point_start, point_end - point_start);
}

double_vector ray::apply(double t) { return point_start_ + direction_ * t; }

unit_vector ray::direction() const { return direction_; }
double_vector ray::point_start() const { return point_start_; }
