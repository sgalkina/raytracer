#include "shapes.h"
#include "ray.h"
#include "vector.h"
#include <cassert>
#include <cmath>

sphere::sphere(double radius_len, double_vector point, double_vector amb,
               double dif, double al)
    : radius_(radius_len), center_(point), ambient_(amb), diffusion_(dif),
      alpha_(al) {}

sphere::sphere() {}

double_vector sphere::ambient() const { return ambient_; }
double sphere::diffusion() const { return diffusion_; }
double sphere::alpha() const { return alpha_; }

double sphere::intersect(ray const &ray) const {
  double_vector c = ray.point_start() - center_;
  double cd = c & ray.direction();
  double t1 = -cd - sqrt(cd * cd - (c & c) + radius_ * radius_);
  if (t1 >= 0)
    return t1;
  return -1;
}

double_vector sphere::normal(double_vector const &P) const {
  double_vector rad_vec = P - center_;
  assert(std::abs(rad_vec.find_length() - radius_) <= 1e-6 &&
         "Point is not on the sphere");
  return rad_vec.get_unit_vector();
}

void sphere::print() const {
  std::cout << "Radius: " << radius_ << "\n"
            << "Center: ";
  center_.print_coordinates();
  std::cout << "Ambient: ";
  ambient_.print_coordinates();
  std::cout << "Diffusion: " << diffusion_ << "\n"
            << "Alpha: " << alpha_ << "\n"
            << std::endl;
}
