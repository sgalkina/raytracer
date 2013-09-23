template < typename T > class RayVector;

template < typename T > 
class RayVector
    {
        T x;
        T y;
        T z;
      public:
        RayVector (T a, T b, T c);
        RayVector ();
        void print_coordinates ();
        RayVector operator+ (RayVector another);
        RayVector operator- (RayVector another);
        T operator& (RayVector another);
        RayVector operator% (RayVector another);
        RayVector operator* (T number);
        double find_length ();
        RayVector get_unit_vector();
    };
 
typedef RayVector<double> DoubleVector;
typedef DoubleVector UnitVec;

class Ray
    {
        UnitVec direction;
        DoubleVector point_start;
        Ray (DoubleVector point, UnitVec direction);
      public:
        static Ray fromPointToDirection (DoubleVector point, DoubleVector rayvector);
        static Ray fromAtoB (DoubleVector point_start, DoubleVector point_end);
        DoubleVector apply (double t);
    };

#include "Vector.tpp"
#include "Ray.tpp"