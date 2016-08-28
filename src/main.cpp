#include "CImg.h"
#include "Colors.h"
#include "Light.h"
#include "Ray.h"
#include "Scene.h"
#include "Shapes.h"
#include "Vector.h"
#include <cmath>
#include <iostream>
#include <string.h>
#include <vector>

int main() {
  DoubleVector origin(0, 0, 0);
  DoubleVector center2(500, 0, -400);
  DoubleVector center3(-150, 0, -450);

  DoubleVector camera_position(0, 800, 0);
  DoubleVector false_up(0, 0, 1);
  Camera camera(camera_position, origin);
  int w = 640;
  int h = 480;
  int r_x = 640;
  int r_y = 480;
  MyScreen screen(w, h, r_x, r_y, camera, 300, false_up);
  DoubleVector shape_ambient1(0.8, 0.8, 0.8);
  DoubleVector shape_ambient2(0.8, 0.3, 0.3);
  DoubleVector shape_ambient3(0.4, 0.9, 0.7);
  Sphere sphere1(300, origin, shape_ambient1, 0.5, 10);
  Sphere sphere2(150, center2, shape_ambient2, 0.8, 10);
  Sphere sphere3(100, center3, shape_ambient3, 0.1, 10);
  std::vector<Sphere> sphere_set;
  sphere_set.push_back(sphere1);
  sphere_set.push_back(sphere2);
  sphere_set.push_back(sphere3);
  DoubleVector light_position(100, 600, 0);
  DoubleVector light_color(1, 1, 1);
  DoubleVector specular_color(0.3, 0.3, 0.3);
  Color light_specular_color(specular_color);
  Light light(light_position, light_color, light_specular_color, 0.8);
  DoubleVector scene_ambient(0.1, 0.2, 0.3);
  Scene scene(camera, screen, sphere_set, scene_ambient, light);

  cimg_library::CImg<unsigned char> img(w, h, 1, 3);
  int a = 1;
  int b = 1;
  DoubleVector new_col(0, 0, 0);
  cimg_forXY(img, x, y) {
    if (a > screen.width_step) {
      a = 1;
    }
    if (b > screen.height_step) {
      b = 1;
    }
    if (a == 1 && b == 1) {
      new_col = scene.get_color_for_coordinates(x, y).decode_to_CImg_format();
    }
    img(x, y, 0, 0) = new_col.x;
    img(x, y, 0, 1) = new_col.y;
    img(x, y, 0, 2) = new_col.z;
    a++;
    b++;
  }
  img.display("Raytracer");

  return 0;
}
