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

class triangle : public shape {
public:
  triangle(double_vector A, double_vector B, double_vector C,
           double_vector ambient, double diffusion, double alpha);
  double intersect(ray const &ray) const;
  double_vector normal(double_vector const &P) const;
  double area(double_vector A, double_vector B, double_vector C) const;
  bool is_inside(double_vector const &P) const;
  double area() const;

private:
  double_vector A_;
  double_vector B_;
  double_vector C_;
  double area_;
};
