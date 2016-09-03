#pragma once
#include "vector.h"

class color {
public:
  color(double_vector const &v);
  color();
  double_vector get_color() const;
  color operator+(color const &other) const;
  color operator^(color const &other) const;
  bool operator==(color const &other) const;
  color operator*(double t) const;
  double_vector decode_to_CImg_format() const;

private:
  double_vector color_;
};
