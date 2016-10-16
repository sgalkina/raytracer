#pragma once
#include "ray.h"
#include "shapes.h"
#include "vector.h"

class sphere : public shape {
public:
  sphere(double radius, double_vector point_center, double_vector ambient,
         double diffusion, double alpha);
  sphere();
  double intersect(ray const &ray) const;
  double_vector normal(double_vector const &P) const;
  void print() const;

private:
  double radius_;
  double_vector center_;
};
