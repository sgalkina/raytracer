#include <iostream>
#include <string.h>
#include <cmath>
#include "CImg.h"
#include "Vector.h"
#include "Ray.h"
#include "Scene.h"
#include "Shapes.h"
#include "Colors.h"
#include "Light.h"

int main()
{
    DoubleVector origin (0, 0, 0);
    DoubleVector camera_position (0, 800, 0);
    Camera camera (camera_position, origin);
    int w = 640;
    int h = 480;
    MyScreen screen (w, h, camera, 300);
    DoubleVector shape_ambient (0.8, 0.8, 0.8);
    Sphere sphere (400, origin, shape_ambient, 0.8);
    DoubleVector light_position (100, 600, 0);
    DoubleVector light_color (0.8, 0.6, 0.7);
    Light light(light_position, light_color);
    DoubleVector scene_ambient (0.1, 0.2, 0.3);
    Scene scene (camera, screen, sphere, scene_ambient, light);

    cimg_library::CImg<unsigned char> img(w,h,1,3);
    cimg_forXY(img,x,y) { 
        DoubleVector new_col = scene.get_color_for_coordinates(x, y).decode_to_CImg_format(); 
        img(x,y,0,0) = new_col.x;
        img(x,y,0,1) = new_col.y;
        img(x,y,0,2) = new_col.z;
    }
    img.display("Raytracer");

    return 0;
}