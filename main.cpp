#include <iostream>
#include <string.h>
#include <math.h>
#include "RayVector.h"

int main()
{
    typedef RayVector<double> DoubleVector;
    DoubleVector viktor (-1, 2, -3);
    viktor.print_coordinates();
    Point<double> A;
    A.x = 1;
    A.z = 2;
    A.y = 3;
    Ray<double> ray (A, viktor);

    return 0;
}