#include <iostream>
#include <string.h>
#include <cmath>
#include "CImg.h"
#include "Vector.h"
#include "Ray.h"
#include "Scene.h"
#include "Shapes.h"
#include "Colors.h"

int main()
{
    DoubleVector origin (0, 0, 0);
    DoubleVector camera_position (0, 80, 100);
    Camera camera (camera_position, origin);
    int w = 640;
    int h = 480;
    Screen1 screen (w, h, camera, 40);
    Sphere sphere (100, origin);
    Scene scene (camera, screen, sphere);

    cimg_library::CImg<unsigned char> img(w,h,1,3);
    cimg_forXY(img,x,y) { 
        unsigned char new_color[] = {0, 0, 0};
        DoubleVector new_col = scene.get_color_for_coordinates(x, y).decode_to_CImg_format(); 
        new_color[0] = new_col.x;
        new_color[1] = new_col.y;
        new_color[2] = new_col.z;
        img(x,y) = * new_color;
    }
    img.display("Raytracer");

    return 0;
}