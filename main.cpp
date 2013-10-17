#include <iostream>
#include <string.h>
#include <cmath>
#include <vector>
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
    DoubleVector center2 (500, 0, -400);
    DoubleVector center3 (-150, 0, -450);
    
    DoubleVector camera_position (0, 800, 0);
    DoubleVector false_up (0, 0, 1);
    Camera camera (camera_position, origin);
    int w = 640;
    int h = 480;
    MyScreen screen (w, h, camera, 300, false_up);
    DoubleVector shape_ambient1 (0.8, 0.8, 0.8);
    DoubleVector shape_ambient2 (0.8, 0.3, 0.3);
    DoubleVector shape_ambient3 (0.4, 0.9, 0.7);
    Sphere sphere1 (300, origin, shape_ambient1, 0.5, 10);
    Sphere sphere2 (150, center2, shape_ambient2, 0.8, 10);
    Sphere sphere3 (100, center3, shape_ambient3, 0.1, 10);
    std::vector<Sphere> sphere_set;
    sphere_set.push_back(sphere1);
    sphere_set.push_back(sphere2);
    sphere_set.push_back(sphere3);
    DoubleVector light_position (100, 600, 0);
    DoubleVector light_color (1, 1, 1);
    DoubleVector specular_color (0.3, 0.3, 0.3);
    Color light_specular_color (specular_color);
    Light light(light_position, light_color, light_specular_color, 0.8);
    DoubleVector scene_ambient (0.1, 0.2, 0.3);
    Scene scene (camera, screen, sphere_set, scene_ambient, light);

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