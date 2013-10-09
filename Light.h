#ifndef LIGHT
#define LIGHT

#include "Vector.h"
#include "Ray.h"
#include "Colors.h"

class Light {
  public:
  	DoubleVector position;
  	DoubleVector color;
  	Color specular_color;
  	double specular_koef;
  	Light(DoubleVector position, DoubleVector color, Color specular_color, double specular_koef);
  	Light();
};

#endif