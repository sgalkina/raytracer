#pragma once
#include "colors.h"
#include "light.h"
#include "ray.h"
#include "shapes.h"
#include "vector.h"
#include <vector>

class camera {
public:
  double_vector position;
  double_vector direction;
  camera(double_vector point_start, double_vector point_end);
  camera();
};

class screen {
  int width;
  int heigth;
  int resolution_x;
  int resolution_y;
  double_vector point_center;
  unit_vector vector_up;
  unit_vector vector_right;
  unit_vector vector_normal;

public:
  int width_step;
  int height_step;
  screen(int w, int h, int r_x, int r_y, camera current_camera, double focus,
         double_vector up);
  screen();
  double_vector get_point(int i, int j);
};

class scene {
private:
  camera camera_;
  screen screen_;

public:
  std::vector<sphere> shapes_set;
  double_vector ambient;
  light light_;
  scene(camera, screen, std::vector<sphere>, double_vector, light);
  ray get_ray(int i, int j);
  color get_color(ray ray);
  color get_color_for_coordinates(int i, int j);
  color get_ambient_color(sphere shape);
  color get_diffuse_color(sphere shape, double_vector point);
  color get_specular_color(sphere shape, double_vector point);
};
