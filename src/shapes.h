#pragma once
#include "ray.h"
#include "vector.h"

class shape {};

class sphere : shape {
  double radius;
  double_vector point_center;

public:
  double_vector ambient;
  double diffusion;
  double alpha;
  sphere(double radius, double_vector point_center, double_vector ambient,
         double diffusion, double alpha);
  sphere();
  double intersect(ray ray);
  double_vector normal(double_vector P);
};
