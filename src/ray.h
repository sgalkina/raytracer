#pragma once
#include "vector.h"

class ray {
  ray(double_vector const &point, unit_vector const &direction);

public:
  static ray from_point_to_direction(double_vector const &point,
                                     double_vector const &direction);
  static ray from_point_to_point(double_vector const &point_start,
                                 double_vector const &point_end);
  double_vector apply(double t);

  unit_vector direction;

  double_vector point_start;

private:
};
