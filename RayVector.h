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
typedef DoubleVector NVec;

class Ray
    {
        NVec direction;
        DoubleVector point_start;
        Ray (DoubleVector point, NVec direction);
      public:
        Ray getRayFromPointAndDirection (DoubleVector point, DoubleVector rayvector);
        Ray getRayFromTwoPoints (DoubleVector point_start, DoubleVector point_end);
        // DoubleVector apply (T t);
    };

#include "Vector.tpp"
#include "Ray.tpp"