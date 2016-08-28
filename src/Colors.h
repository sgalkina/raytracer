#pragma once
#include "Vector.h"

class Color {
public:
  DoubleVector color;
  Color(DoubleVector v);
  Color();
  DoubleVector get_color();
  Color operator+(Color other);
  Color operator^(Color other);
  bool operator==(Color other);
  Color operator*(double t);
  DoubleVector decode_to_CImg_format();
};
