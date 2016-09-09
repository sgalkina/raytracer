// #include "../external/CImg.h"
#include "colors.h"
#include "light.h"
#include "ray.h"
#include "scene.h"
#include "shapes.h"
#include "vector.h"
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>

double random(long from, long to) {
  return rand() % (to - from) + from + ((double)rand() / (RAND_MAX));
}

double_vector random_center(int distance) {
  size_t MAX = distance;
  return double_vector(random(-MAX, MAX), random(0, 0), random(-MAX, MAX));
}

double_vector random_vector(long from, long to) {
  return double_vector(random(from, to), random(from, to), random(from, to));
}

color random_color() { return random_vector(0, 1); }

void make_image(size_t width, size_t height, scene const &sc) {
  std::ofstream f("bin/image.ppm");
  size_t max = 255;
  f << "P6\n" << width << " " << height << "\n" << max << "\n";
  for (size_t y = 0; y < height; ++y) {
    for (size_t x = 0; x < width; ++x) {
      double_vector pixel =
          sc.get_color_for_coordinates(x, y).decode_to_CImg_format();
      f << (char)pixel.x() << (char)pixel.y() << (char)pixel.z();
    }
  }
}

int main() {
  std::srand(std::time(0));

  size_t w = 640;
  size_t h = 640;
  double alpha = 10;
  int distance = 5000;
  double_vector camera_position(0, distance, 0);
  double_vector false_up(0, 0, 1);
  camera camera(camera_position, double_vector(0, 0, 0));
  screen screen(w, h, camera, 300, false_up);
  double_vector light_position(1000, 2800, 300);
  double_vector light_color(1, 1, 1);
  double_vector specular_color(0.3, 0.3, 0.3);
  color light_specular_color(specular_color);
  light light(light_position, light_color, light_specular_color, 0.8);
  double_vector scene_ambient(0.3, 0.3, 0.3);

  size_t n = 0;
  std::vector<std::shared_ptr<shape>> shape_set;
  for (size_t i = 0; i < n; ++i) {
    std::shared_ptr<shape> sphere_(
        // new sphere(random(distance / 20, distance / 5),
        // random_center(distance),
        //            random_vector(0, 1), random(0, 1), alpha));
        new sphere(1000, double_vector(1000, 0, 2000), random_vector(0, 1),
                   random(0, 1), alpha));
    shape_set.push_back(sphere_);

    std::shared_ptr<shape> sphere2_(
        // new sphere(random(distance / 20, distance / 5),
        // random_center(distance),
        //            random_vector(0, 1), random(0, 1), alpha));
        new sphere(1000, double_vector(-2000, 0, 2000), random_vector(0, 1),
                   random(0, 1), alpha));
    shape_set.push_back(sphere2_);
    std::shared_ptr<shape> sphere3_(
        // new sphere(random(distance / 20, distance / 5),
        // random_center(distance),
        //            random_vector(0, 1), random(0, 1), alpha));
        new sphere(1000, double_vector(1000, 0, 1000), random_vector(0, 1),
                   random(0, 1), alpha));
    shape_set.push_back(sphere3_);
  }
  size_t k = 1;
  for (size_t i = 0; i < k; ++i) {
    std::shared_ptr<shape> triangle_(new triangle(
        double_vector(1000, 0, 2000), double_vector(-2000, 0, 2000),
        double_vector(1000, 0, 1000), random_vector(0, 1), random(0, 1),
        alpha));
    shape_set.push_back(triangle_);
  }

  scene scenere(camera, screen, shape_set, scene_ambient, light);
  make_image(w, h, scenere);

  // cimg_library::CImg<unsigned char> img(w, h, 1, 3);
  // double_vector new_col(0, 0, 0);
  // cimg_forXY(img, x, y) {
  //   new_col = scene.get_color_for_coordinates(x,
  //   y).decode_to_CImg_format();
  //   img(x, y, 0, 0) = new_col.x();
  //   img(x, y, 0, 1) = new_col.y();
  //   img(x, y, 0, 2) = new_col.z();
  // }
  // img.display("raytracer");

  return 0;
}
