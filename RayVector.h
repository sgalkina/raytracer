template < typename T >
struct Point {
    T x; T y; T z;

    void print_point() {
        std::cout << "X: " << x << std::endl;
        std::cout << "Y: " << y << std::endl;
        std::cout << "Z: " << z << std::endl;
    }
};

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
        Point<T> get_coordinates ();
        RayVector operator+ (RayVector another);
        RayVector operator- (RayVector another);
        T operator& (RayVector another);
        RayVector operator% (RayVector another);
        RayVector operator* (T number);
        double find_length ();
        RayVector get_unit_vector();
    };

template < typename T > class Ray;

template < typename T > 
class Ray
    {
        RayVector<T> unit_vector;
        Point<T> start_point;
      public:
        Ray (RayVector<T> rayvector);
        Ray (Point<T> A, Point<T> B);
        Point<T> apply (T t);
    };

#include "Vector.tpp"
#include "Ray.tpp"