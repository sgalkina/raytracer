#include "scene.h"
#include "colors.h"
#include "light.h"
#include "ray.h"
#include "shapes.h"
#include "vector.h"
#include <cmath>
#include <iostream>
#include <vector>

camera::camera(double_vector point_start, double_vector point_end) {
  position = point_start;
  direction = (point_end - point_start).get_unit_vector();
}

camera::camera() {}

screen::screen(size_t w, size_t h, camera current_camera, double focus,
               double_vector up)
    : width_(w), heigth_(h),
      center_(current_camera.position + current_camera.direction * focus),
      normal_(current_camera.direction),
      right_((normal_ % up).get_unit_vector()),
      up_((right_ % normal_).get_unit_vector()) {}

screen::screen() {}

double_vector screen::get_point(int i, int j) const {
  return center_ + right_ * (i - (int)width_ / 2) +
         up_ * (j - (int)heigth_ / 2);
}

scene::scene(camera c, screen sc, std::vector<sphere> shapes, double_vector amb,
             light l) {
  camera_ = c;
  screen_ = sc;
  shapes_set = shapes;
  ambient = amb;
  light_ = l;
}

ray scene::get_ray(int i, int j) const {
  return ray::from_point_to_point(camera_.position, screen_.get_point(i, j));
}

color scene::get_color(ray ray) const {
  double t_min = 1e+15;
  size_t j = -1;
  double t = -1;
  for (size_t i = 0; i < shapes_set.size(); ++i) {
    t = shapes_set[i].intersect(ray);
    if (std::abs(t + 1) > 1e-6 && t < t_min) {
      t_min = t;
      j = i;
    }
  }
  if (std::abs(t_min - 1e+15) < 1e-6) {
    return double_vector(0, 0, 0);
  }
  double_vector point = ray.apply(t_min);
  color amb_color = get_ambient_color(shapes_set[j]);
  // color dif_color = bl;
  color dif_color = get_diffuse_color(shapes_set[j], point);
  // color spec_color = bl;
  color spec_color = get_specular_color(shapes_set[j], point);
  return amb_color + dif_color + spec_color;
}

color scene::get_ambient_color(sphere shape) const {
  return ambient ^ shape.ambient();
}

color scene::get_diffuse_color(sphere shape, double_vector point) const {
  double sk =
      (light_.position() - point).get_unit_vector() & shape.normal(point);
  return light_.colour() * (shape.diffusion() * sk);
}

color scene::get_specular_color(sphere shape, double_vector point) const {
  double_vector light_direction = (point - light_.position()).get_unit_vector();
  double sk = light_direction & shape.normal(point);
  double_vector reflected = light_direction - shape.normal(point) * 2 * sk;
  double_vector camera_view = (camera_.position - point).get_unit_vector();
  double reflected_sk = reflected & camera_view;
  reflected_sk = std::max(reflected_sk, 0.0);
  return light_.specular_color() * light_.specular_coef() *
         std::pow(reflected_sk, shape.alpha());
}

color scene::get_color_for_coordinates(int i, int j) const {
  ray ray = get_ray(i, j);
  return get_color(ray);
}
