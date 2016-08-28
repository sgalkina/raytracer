#pragma once
#include "colors.h"
#include "ray.h"
#include "vector.h"

class light {
public:
  double_vector position;
  double_vector color_;
  color specular_color;
  double specular_koef;
  light(double_vector position, double_vector the_color, color specular_color,
        double specular_koef);
  light();
};
