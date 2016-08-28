#pragma once
#include "vector.h"

class color {
public:
  double_vector color_;
  color(double_vector v);
  color();
  double_vector get_color();
  color operator+(color other);
  color operator^(color other);
  bool operator==(color other);
  color operator*(double t);
  double_vector decode_to_CImg_format();
};
