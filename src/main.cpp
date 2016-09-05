#include "../external/CImg.h"
#include "colors.h"
#include "light.h"
#include "ray.h"
#include "scene.h"
#include "shapes.h"
#include "vector.h"
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <vector>

double random(long from, long to) {
  return rand() % (to - from) + from + ((double)rand() / (RAND_MAX));
}

double_vector random_center(size_t width, size_t heigth) {
  long MAX = 800;
  return double_vector(random(-MAX, MAX), 0, random(-MAX, MAX));
  // return double_vector(random(-MAX, MAX), random(-MAX, MAX), random(-MAX,
  // MAX));
}

double_vector random_vector(long from, long to) {
  return double_vector(random(from, to), random(from, to), random(from, to));
}

color random_color() { return random_vector(0, 1); }

int main() {
  std::srand(std::time(0));

  size_t w = 640;
  size_t h = 640;
  double alpha = 10;
  double_vector camera_position(0, 1600, 0);
  double_vector false_up(0, 0, 1);
  camera camera(camera_position, double_vector(0, 0, 0));
  screen screen(w, h, camera, 300, false_up);
  double_vector light_position(0, 2800, 0);
  double_vector light_color(1, 1, 1);
  double_vector specular_color(0.3, 0.3, 0.3);
  color light_specular_color(specular_color);
  light light(light_position, light_color, light_specular_color, 0.8);
  double_vector scene_ambient(0.3, 0.3, 0.3);

  size_t n = 5;
  std::vector<sphere> sphere_set;
  for (size_t i = 0; i < n; ++i) {
    sphere sphere_(random(100, 400), random_center(2000, 2000),
                   random_vector(0, 1), random(0, 1), alpha);
    sphere_.print();
    sphere_set.push_back(sphere_);
  }

  scene scene(camera, screen, sphere_set, scene_ambient, light);

  cimg_library::CImg<unsigned char> img(w, h, 1, 3);
  double_vector new_col(0, 0, 0);
  cimg_forXY(img, x, y) {
    new_col = scene.get_color_for_coordinates(x, y).decode_to_CImg_format();
    img(x, y, 0, 0) = new_col.x();
    img(x, y, 0, 1) = new_col.y();
    img(x, y, 0, 2) = new_col.z();
  }
  img.display("raytracer");

  return 0;
}
