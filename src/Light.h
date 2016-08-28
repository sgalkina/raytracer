#pragma once
#include "Colors.h"
#include "Ray.h"
#include "Vector.h"

class Light {
public:
  DoubleVector position;
  DoubleVector color;
  Color specular_color;
  double specular_koef;
  Light(DoubleVector position, DoubleVector color, Color specular_color,
        double specular_koef);
  Light();
};
