#include <iostream>
#include <string.h>
#include <math.h>
#include "RayVector.h"

int main()
{
    DoubleVector viktor (-1, 2, -3);
    viktor.print_coordinates();
    
    DoubleVector gektor (2, 3, 4);
    gektor.print_coordinates();

    Ray Ray.getRayFromPointAndDirection(viktor, gektor);

    return 0;
}