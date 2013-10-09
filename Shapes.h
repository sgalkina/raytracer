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
        DoubleVector ambient;
        double diffusion;
        double alpha;
        Sphere (double radius, DoubleVector point_center, DoubleVector ambient, double diffusion, double alpha);
        Sphere ();
        double intersect(Ray ray);
        DoubleVector normal (DoubleVector P);
    };

#endif