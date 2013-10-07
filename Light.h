#ifndef LIGHT
#define LIGHT

#include "Vector.h"
#include "Ray.h"
#include "Colors.h"

class Light {
  public:
  	DoubleVector position;
  	DoubleVector color;
  	Light(DoubleVector position, DoubleVector color);
  	Light();
};

#endif