#include "triangle.h"
#include "ray.h"
#include "shapes.h"
#include "vector.h"
#include <cassert>
#include <cmath>
#include <vector>

triangle::triangle(double_vector A, double_vector B, double_vector C,
                   std::vector<double_vector> const &normals, double_vector amb,
                   double dif, double al)
    : shape(amb, dif, al), A_(A), normals_(normals), AB_(B - A), AC_(C - A) {}

double triangle::intersect(ray const &ray) const {
  double_vector normal_ = AB_ % AC_;
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

double_vector ortogonal(double_vector const &a, double_vector const &b) {
  return b - (a * ((b & a) / (a & a)));
}

double_vector triangle::normal(double_vector const &P) const {
  double_vector v = P - A_;
  double_vector abn = ortogonal(AB_, AC_);
  double_vector acn = ortogonal(AC_, AB_);
  double x = (v & acn) / (AB_ & acn);
  double y = (v & abn) / (AC_ & abn);
  double z = 1 - x - y;
  return double_vector(normals_[1] * x + normals_[2] * y + normals_[0] * z);
}
