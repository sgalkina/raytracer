#include "../external/CImg.h"
#include "colors.h"
#include "light.h"
#include "ray.h"
#include "scene.h"
#include "shapes.h"
#include "vector.h"
#include <cmath>
#include <iostream>
#include <string.h>
#include <vector>

int main() {
  double_vector origin(0, 0, 0);
  double_vector center2(500, 0, -400);
  double_vector center3(-150, 0, -450);

  double_vector camera_position(0, 800, 0);
  double_vector false_up(0, 0, 1);
  camera camera(camera_position, origin);
  int w = 640;
  int h = 480;
  int r_x = 640;
  int r_y = 480;
  screen screen(w, h, r_x, r_y, camera, 300, false_up);
  double_vector shape_ambient1(0.8, 0.8, 0.8);
  double_vector shape_ambient2(0.8, 0.3, 0.3);
  double_vector shape_ambient3(0.4, 0.9, 0.7);
  sphere sphere1(300, origin, shape_ambient1, 0.5, 10);
  sphere sphere2(150, center2, shape_ambient2, 0.8, 10);
  sphere sphere3(100, center3, shape_ambient3, 0.1, 10);
  std::vector<sphere> sphere_set;
  sphere_set.push_back(sphere1);
  sphere_set.push_back(sphere2);
  sphere_set.push_back(sphere3);
  double_vector light_position(100, 600, 0);
  double_vector light_color(1, 1, 1);
  double_vector specular_color(0.3, 0.3, 0.3);
  color light_specular_color(specular_color);
  light light(light_position, light_color, light_specular_color, 0.8);
  double_vector scene_ambient(0.1, 0.2, 0.3);
  scene scene(camera, screen, sphere_set, scene_ambient, light);

  cimg_library::CImg<unsigned char> img(w, h, 1, 3);
  int a = 1;
  int b = 1;
  double_vector new_col(0, 0, 0);
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
  img.display("raytracer");

  return 0;
}
