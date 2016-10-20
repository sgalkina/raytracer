#include "triangle.h"
#include "ray.h"
#include "shapes.h"
#include "vector.h"
#include <cassert>
#include <cmath>

triangle::triangle(double_vector A, double_vector B, double_vector C,
                   double_vector amb, double dif, double al)
    : shape(amb, dif, al), A_(A), B_(B), C_(C), AB_(B - A), AC_(C - A),
      normal_((AB_ % AC_).get_unit_vector()) {}

double triangle::intersect(ray const &ray) const {
  double a = ray.direction() & normal_;
  double b = (A_ - ray.point_start()) & normal_;
  double t = b / a;

  double_vector intersection = ray.apply(t) - A_;

  double_vector ac_d = AC_ % ray.direction();
  double alpha = (ac_d & intersection) / (ac_d & AB_);

  double_vector ab_d = AB_ % ray.direction();
  double beta = (ab_d & intersection) / (ab_d & AC_);

  if (t >= 0 && 0 <= alpha && alpha <= 1 && 0 <= beta && beta <= 1 &&
      alpha + beta <= 1) {
    return t;
  }
  return -1;
}

double_vector triangle::normal(double_vector const &P) const {
  return ((A_ - P) % (C_ - P)).get_unit_vector();
}
