#include "colors.h"
#include "vector.h"
#include <cmath>

color::color(double_vector v) { color_ = v; }

color::color() {}

double_vector color::get_color() { return color_; }

color color::operator+(color other) { return color_ + other.get_color(); }

color color::operator^(color other) { return color_ ^ other.get_color(); }

color color::operator*(double t) { return color_ * t; }

bool color::operator==(color other) { return color_ == other.get_color(); }

double_vector color::decode_to_CImg_format() {
  double_vector control_color(std::max(color_.x, 0.0), std::max(color_.y, 0.0),
                              std::max(color_.z, 0.0));
  double_vector new_control_color(std::min(control_color.x, 1.0),
                                  std::min(control_color.y, 1.0),
                                  std::min(control_color.z, 1.0));
  return new_control_color * 255;
}
