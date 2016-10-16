#include "shapes.h"
#include "vector.h"
#include <cassert>
#include <cmath>

shape::shape(double_vector amb, double dif, double al)
    : ambient_(amb), diffusion_(dif), alpha_(al) {}

shape::shape() : ambient_(double_vector(0, 0, 0)), diffusion_(0), alpha_(0) {}

double_vector shape::ambient() const { return ambient_; }
double shape::diffusion() const { return diffusion_; }
double shape::alpha() const { return alpha_; }
