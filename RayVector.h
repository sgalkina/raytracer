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