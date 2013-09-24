#include <iostream>
#include <string.h>
#include <math.h>
#include "RayVectorShapes.h"
#include "Scene.h"

int main()
{
    DoubleVector viktor (1, 1, 0);
    DoubleVector gektor (0, 0, 0);
    Camera camera (gektor, viktor);
    Screen screen (640, 480, camera, 5.0);

    return 0;
}