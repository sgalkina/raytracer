#pragma once
#include "colors.h"
#include "light.h"
#include "ray.h"
#include "shapes.h"
#include "vector.h"
#include <memory>
#include <vector>

class camera {
public:
  double_vector position;
  double_vector direction;
  camera(double_vector point_start, double_vector point_end);
  camera();
};

class screen {
public:
  screen(size_t w, size_t h, size_t w_res, size_t h_res, camera current_camera,
         double focus, double_vector up);
  screen();
  double_vector get_point(int i, int j) const;

private:
  size_t width_;
  size_t heigth_;
  size_t width_res_;
  size_t heigth_res_;
  double_vector center_;
  unit_vector normal_;
  unit_vector right_;
  unit_vector up_;
};

class scene {
private:
  camera camera_;
  screen screen_;

public:
  std::vector<std::shared_ptr<shape>> shapes_set;
  double_vector ambient;
  light light_;
  scene(camera, screen, std::vector<std::shared_ptr<shape>>, double_vector,
        light);
  ray get_ray(int i, int j) const;
  color get_color(ray ray) const;
  color get_color_for_coordinates(int i, int j) const;
  color get_ambient_color(std::shared_ptr<shape> const shape_) const;
  color get_diffuse_color(std::shared_ptr<shape> const shape_,
                          double_vector point) const;
  color get_specular_color(std::shared_ptr<shape> const shape_,
                           double_vector point) const;
};
