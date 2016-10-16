#pragma once
#include "ray.h"
#include "vector.h"

class shape {
protected:
  shape(double_vector ambient, double diffusion, double alpha);
  shape();

public:
  virtual double intersect(ray const &) const = 0;
  virtual double_vector normal(double_vector const &) const = 0;
  double diffusion() const;
  double alpha() const;
  double_vector ambient() const;

private:
  double_vector ambient_;
  double diffusion_;
  double alpha_;
};
