#include <iostream>
#include <string.h>
#include <math.h>
#include "RayVector.h"

int main()
{
    typedef RayVector<double> DoubleVector;
    DoubleVector viktor (-1, 2, -3);
    viktor.print_coordinates();
    Ray<double> ray (viktor);
    Point<double> point = ray.apply(3.4);
    Point<double> point3 = ray.apply(5.4);
    Ray<double> ray2 (Point<double> point, Point<double> point3);
    Point<double> point2 = ray2.apply(3.4);
    point2.print_point();

    return 0;
}