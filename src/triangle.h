#pragma once
#include "ray.h"
#include "shapes.h"
#include "vector.h"
#include <vector>

class triangle : public shape {
public:
  triangle(double_vector A, double_vector B, double_vector C,
           std::vector<double_vector> const &normals, double_vector ambient,
           double diffusion, double alpha);
  double intersect(ray const &ray) const;
  double_vector normal(double_vector const &P) const;

private:
  double_vector A_;
  double_vector B_;
  double_vector C_;
  std::vector<double_vector> normals_;
  double_vector AB_;
  double_vector AC_;
  double_vector normal_;
};
