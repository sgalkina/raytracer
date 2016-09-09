#pragma once
#include "vector.h"

class ray {
  ray(double_vector const &point, unit_vector const &direction);

public:
  static ray from_point_to_direction(double_vector const &point,
                                     double_vector const &direction);
  static ray from_point_to_point(double_vector const &point_start,
                                 double_vector const &point_end);

  unit_vector direction() const;
  double_vector point_start() const;
  double_vector apply(double t) const;

private:
  unit_vector direction_;
  double_vector point_start_;
};
