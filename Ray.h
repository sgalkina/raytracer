#ifndef RAY
#define RAY

class Ray
    {
        UnitVec direction;
        DoubleVector point_start;
        Ray (DoubleVector point, UnitVec direction);
      public:
        static Ray fromPointToDirection (DoubleVector point, DoubleVector rayvector);
        static Ray fromAtoB (DoubleVector point_start, DoubleVector point_end);
        DoubleVector get_start_point ();
        UnitVec get_direction ();
        DoubleVector apply (double t);
    };

#endif