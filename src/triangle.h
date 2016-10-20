#pragma once
#include "ray.h"
#include "shapes.h"
#include "vector.h"

class triangle : public shape {
public:
  triangle(double_vector A, double_vector B, double_vector C,
           double_vector ambient, double diffusion, double alpha);
  double intersect(ray const &ray) const;
  double_vector normal(double_vector const &P) const;

private:
  double_vector A_;
  double_vector B_;
  double_vector C_;
  double_vector AB_;
  double_vector AC_;
  double_vector normal_;
};
