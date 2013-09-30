#include "Vector.h"
#include "Ray.h"
#include "Shapes.h"
#include "Scene.h"

Ray :: Ray (DoubleVector point, UnitVec rayvector)
    {
        point_start = point;
        direction = rayvector;
    }

DoubleVector Ray :: get_start_point ()
     {
         return point_start;
     }

UnitVec Ray :: get_direction ()
     {
         return direction;
     }

Ray Ray :: fromPointToDirection (DoubleVector point, DoubleVector rayvector) {
    return Ray(point, rayvector.get_unit_vector());
}

Ray Ray :: fromAtoB (DoubleVector point_start, DoubleVector point_end) {
    DoubleVector point = point_start;
    DoubleVector direction = point_end - point_start;
    return fromPointToDirection(point, direction);
}

DoubleVector Ray :: apply (double t)
     {
         DoubleVector vector_end = direction*t;
         return point_start + vector_end;
     }