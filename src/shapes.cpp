#include "shapes.h"
#include "ray.h"
#include "vector.h"
#include <cassert>
#include <cmath>

shape::shape(double_vector amb, double dif, double al)
    : ambient_(amb), diffusion_(dif), alpha_(al) {}

shape::shape() : ambient_(double_vector(0, 0, 0)), diffusion_(0), alpha_(0) {}

double_vector shape::ambient() const { return ambient_; }
double shape::diffusion() const { return diffusion_; }
double shape::alpha() const { return alpha_; }

sphere::sphere(double radius_len, double_vector point, double_vector amb,
               double dif, double al)
    : shape(amb, dif, al), radius_(radius_len), center_(point) {}

sphere::sphere() : shape(), radius_(0), center_(double_vector(0, 0, 0)) {}

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
  ambient().print_coordinates();
  std::cout << "Diffusion: " << diffusion() << "\n"
            << "Alpha: " << alpha() << "\n"
            << std::endl;
}
