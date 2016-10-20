// #include "../external/CImg.h"
#include "colors.h"
#include "light.h"
#include "ray.h"
#include "scene.h"
#include "sphere.h"
#include "triangle.h"
#include "vector.h"
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
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

std::vector<std::shared_ptr<shape>> read_model() {
  double alpha = 10;
  ray_vector<double> ambient = random_vector(0, 1);
  double diffusion = random(0, 1);
  std::vector<std::shared_ptr<shape>> result;
  std::vector<double_vector> vertexes;
  std::vector<double_vector> normals;
  std::ifstream f("models/utah.obj");
  std::string line;
  if (f.is_open()) {
    while (getline(f, line)) {
      if (line[0] == 'v' && line[1] != 't') {
        std::vector<double> holder;
        std::istringstream s(line);
        for (std::string l; std::getline(s, l, ' ');) {
          if (l != "" && l[0] != 'v') {
            holder.push_back(std::stod(l));
          }
        }
        if (line[1] == 'n') {
          normals.push_back(double_vector(holder[0], holder[1], holder[2]));
          normals[normals.size() - 1] =
              normals[normals.size() - 1].get_unit_vector();
        } else {
          vertexes.push_back(double_vector(holder[0], holder[1], holder[2]));
        }
        holder.clear();
      } else if (line[0] == 'f') {
        assert(vertexes.size() == normals.size() &&
               "Numbers of normals is not the same as number of vectors");
        std::vector<double_vector> holder;
        std::vector<double_vector> normals_;
        std::istringstream s(line);
        for (std::string l; std::getline(s, l, ' ');) {
          if (l != "" && l[0] != 'f') {
            std::istringstream inner(l);
            for (std::string i; std::getline(inner, i, '\\');) {
              holder.push_back(vertexes[std::stoi(i) - 1]);
              normals_.push_back(normals[std::stoi(i) - 1]);
              break;
            }
          }
        }
        std::shared_ptr<shape> triangle_(
            new triangle(holder[0], holder[1], holder[2], normals_, ambient,
                         diffusion, alpha));
        result.push_back(triangle_);
        holder.clear();
        normals_.clear();
      }
    }
    f.close();
  }
  return result;
}

int main() {
  std::srand(std::time(0));

  size_t w = 40;
  size_t h = 30;
  size_t w_res = 640;
  size_t h_res = 480;
  double_vector camera_position(0, 40, 90);
  double_vector false_up(0, 0, -1);
  camera camera(camera_position, double_vector(0, 0, 0));
  screen screen(w, h, w_res, h_res, camera, 80, false_up);
  double_vector light_position(80, -150, 50);
  double_vector light_color(1, 1, 1);
  double_vector specular_color(0.3, 0.3, 0.3);
  color light_specular_color(specular_color);
  light light(light_position, light_color, light_specular_color, 0.8);
  double_vector scene_ambient(0.3, 0.3, 0.3);
  scene scenere(camera, screen, read_model(), scene_ambient, light);
  make_image(w_res, h_res, scenere);

  return 0;
}
