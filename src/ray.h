#pragma once
#include "vector.h"

class ray {
  ray(double_vector point, unit_vector direction);

public:
  unit_vector direction;
  double_vector point_start;
  static ray from_point_to_direction(double_vector point, double_vector direction);
  static ray from_point_to_point(double_vector point_start,
                                 double_vector point_end);
  double_vector apply(double t);
};
