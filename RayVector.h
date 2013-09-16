template < typename T > class RayVector;

template < typename T > 
class RayVector
    {
        T x;
        T y;
        T z;
      public:
        RayVector (T a, T b, T c);
        void print_coordinates ();
        RayVector operator+ (RayVector another);
        RayVector operator- (RayVector another);
        T operator& (RayVector another);
        RayVector operator% (RayVector another);
        RayVector operator* (T number);
        double find_length ();
        RayVector get_unit_vector();
    };

template < typename T > 
struct Point {
    T x, y, z;
};

template < typename T > class Ray;

template < typename T > 
class Ray
    {
        Point<T> point;
        RayVector<T> direction;
      public:
        Ray (Point<T> startpoint, RayVector<T> rayvector);
    };

#include "Vector.tpp"
#include "Ray.tpp"