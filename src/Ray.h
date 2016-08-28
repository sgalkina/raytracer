#ifndef RAY
#define RAY

#include "Vector.h"

class Ray {
  Ray(DoubleVector point, UnitVec direction);

public:
  UnitVec direction;
  DoubleVector point_start;
  static Ray fromPointToDirection(DoubleVector point, DoubleVector direction);
  static Ray fromAtoB(DoubleVector point_start, DoubleVector point_end);
  DoubleVector apply(double t);
};

#endif
