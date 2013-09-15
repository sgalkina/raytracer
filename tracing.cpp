#include <iostream>
#include <string.h>
#include <math.h>
using namespace std; 

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
    };

template < typename T > 
RayVector<T> :: RayVector (T a, T b, T c)
    {
        x = a; y = b; z = c;
    }

template < typename T > 
void RayVector<T> :: print_coordinates () 
    {
        cout << "X: " << x << endl;
        cout << "Y: " << y << endl;
        cout << "Z: " << z << endl;
    }

template < typename T > 
RayVector<T> RayVector<T> :: operator+ (RayVector<T> another) 
    {
        return RayVector<T> (x + another.x,
                             y + another.y,
                             z + another.z);
    }

template < typename T > 
RayVector<T> RayVector<T> :: operator- (RayVector<T> another) 
    {
        return RayVector<T> (x - another.x,
                             y - another.y,
                             z - another.z);
    }

template < typename T > 
T RayVector<T> :: operator& (RayVector<T> another) 
    {
        return x*another.x + y*another.y + z*another.z;
    }

template < typename T > 
RayVector<T> RayVector<T> :: operator% (RayVector<T> another) 
    {
        return RayVector<T> (y*another.z - z*another.y,
                             z*another.x - x*another.z,
                             x*another.y - y*another.x);
    }

template < typename T > 
RayVector<T> RayVector<T> :: operator* (T number) 
    {
        return RayVector<T> (x*number,
                             y*number,
                             z*number);
    }

template < typename T > 
double RayVector<T> :: find_length () 
    {
        return sqrt(x*x + y*y + z*z);
    }

int main()
{
    RayVector<int> viktor (-1, 2, -3);
    RayVector<int> gektor (0, -4, 1);
    cout << (viktor & gektor) << endl;
    cout << "length " << viktor.find_length() << endl;
    (viktor % gektor).print_coordinates();
    (viktor * 5).print_coordinates();
    string s = "x";
    string e = "e";
    while (s.compare(e) != 0) {
        cout << "Enter 'e' for exit: ";
        cin >> s;
    }
    return 0;
}