#pragma once
#include "ray.h"
#include "vector.h"

class shape {
  virtual double intersect(ray const &) const = 0;
  virtual double_vector normal(double_vector const &) const = 0;
};

class sphere : shape {
public:
  sphere(double radius, double_vector point_center, double_vector ambient,
         double diffusion, double alpha);
  sphere();
  double intersect(ray const &ray) const;
  double_vector normal(double_vector const &P) const;
  double_vector ambient() const;
  double diffusion() const;
  double alpha() const;
  void print() const;

private:
  double radius_;
  double_vector center_;
  double_vector ambient_;
  double diffusion_;
  double alpha_;
};
