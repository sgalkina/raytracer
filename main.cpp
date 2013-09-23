#include <iostream>
#include <string.h>
#include <math.h>
#include "RayVector.h"

int main()
{
    DoubleVector viktor (1, 1, 0);
    DoubleVector gektor (0, 0, 0);
    Ray ray = Ray :: fromPointToDirection(gektor, viktor);
    Sphere sphere (2, gektor);
    double t = sphere.intersect(ray);
    std::cout << t << std::endl;

    DoubleVector helper (sqrt(2), sqrt(2), 0);
    DoubleVector norm = sphere.normal(helper);
    norm.print_coordinates();

    return 0;
}