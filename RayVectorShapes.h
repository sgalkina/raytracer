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
        DoubleVector get_start_point ();
        UnitVec get_direction ();
        DoubleVector apply (double t);
    };

class Shape 
    {

    };

class Sphere : Shape 
    {
        double radius;
        DoubleVector point_center;
      public:
        Sphere (double radius, DoubleVector point_center);
        double intersect(Ray ray);
        DoubleVector normal (DoubleVector P);
    };

#include "Vector.tpp"
#include "Ray.cpp"
#include "Shapes.cpp"