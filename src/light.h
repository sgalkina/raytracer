#pragma once
#include "colors.h"
#include "vector.h"

class light {

public:
  light(double_vector position, double_vector the_color, color specular_color,
        double specular_koef);
  light();

  double_vector position() const;
  double_vector colour() const;
  color specular_color() const;
  double specular_coef() const;

private:
  double_vector position_;
  double_vector color_;
  color specular_color_;
  double specular_coef_;
};
