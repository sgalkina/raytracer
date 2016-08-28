#include "Colors.h"
#include "Vector.h"
#include <cmath>

Color::Color(DoubleVector v) { color = v; }

Color::Color() {}

DoubleVector Color::get_color() { return color; }

Color Color::operator+(Color other) { return color + other.get_color(); }

Color Color::operator^(Color other) { return color ^ other.get_color(); }

Color Color::operator*(double t) { return color * t; }

bool Color::operator==(Color other) { return color == other.get_color(); }

DoubleVector Color::decode_to_CImg_format() {
  DoubleVector control_color(std::max(color.x, 0.0), std::max(color.y, 0.0),
                             std::max(color.z, 0.0));
  DoubleVector new_control_color(std::min(control_color.x, 1.0),
                                 std::min(control_color.y, 1.0),
                                 std::min(control_color.z, 1.0));
  return new_control_color * 255;
}
