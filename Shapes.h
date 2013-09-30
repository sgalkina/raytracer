#ifndef SHAPES
#define SHAPES

#include "Vector.h"
#include "Ray.h"

class Shape 
    {

    };

class Sphere : Shape 
    {
        double radius;
        DoubleVector point_center;
      public:
        Sphere (double radius, DoubleVector point_center);
        Sphere ();
        double intersect(Ray ray);
        DoubleVector normal (DoubleVector P);
    };

#endif