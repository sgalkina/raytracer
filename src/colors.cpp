#include "colors.h"
#include "vector.h"
#include <cmath>

color::color(double_vector const &v) : color_(v) {}

color::color() {}

double_vector color::get_color() const { return color_; }

color color::operator+(color const &other) const {
  return color_ + other.get_color();
}

color color::operator^(color const &other) const {
  return color_ ^ other.get_color();
}

color color::operator*(double t) const { return color_ * t; }

bool color::operator==(color const &other) const {
  return color_ == other.get_color();
}

double adjust(double n) { return std::min(std::max(n, 0.0), 1.0); }

double_vector color::decode_to_CImg_format() const {
  double_vector control_color(adjust(color_.x()), adjust(color_.y()),
                              adjust(color_.z()));
  return control_color * 255;
}
