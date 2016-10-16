#include "triangle.h"
#include "ray.h"
#include "shapes.h"
#include "vector.h"
#include <cassert>
#include <cmath>

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
