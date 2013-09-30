#include <iostream>
#include <string.h>
#include <math.h>
#include "Vector.h"
#include "Ray.h"
#include "Shapes.h"
#include "Scene.h"

int main()
{
    DoubleVector viktor (1, 1, 0);
    DoubleVector gektor (0, 0, 0);
    Camera camera (gektor, viktor);
    int w = 40;
    int h = 40;
    DoubleVector wh (1, 1, 1);
    Color white (wh);
    DoubleVector bl (0, 0, 0);
    Color black (bl);
    Screen screen (w, h, camera, 1.0);
    DoubleVector scen (3, 3, 8);
    Sphere sphere (2, scen);
    Scene scene (camera, screen, sphere);
    for (int j = 0; j < h; j++) {
        for (int i = 0; i < w; i++) {
            if (i == 0) {
                std::cout << "\n";
            }
        if (scene.get_color_for_coordinates(i, j) == white) {
            std::cout << "o ";
        }
        else {
            std::cout << "x ";
        }
    }
    }
    std::cout << "\n";
    return 0;
}