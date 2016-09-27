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

triangle::triangle(double_vector A, double_vector B, double_vector C,
                   double_vector amb, double dif, double al)
    : shape(amb, dif, al), A_(A), B_(B), C_(C), area_(area()) {}

double triangle::area(double_vector A, double_vector B, double_vector C) const {
  double_vector cross = (A - B) % (A - C);
  double result = 0.5 * sqrt(cross.x() * cross.x() + cross.y() * cross.y() +
                             cross.z() * cross.z());
  assert(result >= 0 && "Area is less than zero");
  return result;
}

double triangle::area() const { return area(A_, B_, C_); }

bool triangle::is_inside(double_vector const &P) const {
  double a = area(A_, C_, P) / area_;
  double b = area(B_, C_, P) / area_;
  double c = area(A_, B_, P) / area_;
  return (a <= 1 && b <= 1 && (std::abs(1 - a - b - c) < 1e-6));
}

double triangle::intersect(ray const &ray) const {
  double_vector P = B_;
  double_vector norm = normal(P);
  double denominator = norm & (ray.apply(1) - ray.point_start());
  if (std::abs(denominator) < 1e-6)
    return -1;
  double t = (norm & (P - ray.point_start())) / denominator;
  double_vector V = ray.apply(t);
  if (is_inside(V)) {
    return t;
  }
  return -1;
}

double_vector triangle::normal(double_vector const &P) const {
  return ((A_ - P) % (C_ - P)).get_unit_vector();
}
