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

screen::screen(int w, int h, int r_x, int r_y, camera current_camera,
               double focus, double_vector up) {
  width = w;
  heigth = h;
  resolution_x = r_x;
  resolution_y = r_y;
  w / r_x < 1 ? width_step = 1 : width_step = w / r_x;
  h / r_y < 1 ? height_step = 1 : height_step = h / r_y;
  point_center = current_camera.position + current_camera.direction * focus;
  vector_normal = current_camera.direction;
  vector_right = (vector_normal % up).get_unit_vector();
  vector_up = (vector_right % vector_normal).get_unit_vector();
}

screen::screen() {}

double_vector screen::get_point(int i, int j) {
  int ci = width / 2;
  int cj = heigth / 2;
  return point_center + vector_right * (i - ci) + vector_up * (j - cj);
}

scene::scene(camera c, screen sc, std::vector<sphere> shapes, double_vector amb,
             light l) {
  camera_ = c;
  screen_ = sc;
  shapes_set = shapes;
  ambient = amb;
  light_ = l;
}

ray scene::get_ray(int i, int j) {
  double_vector point_end = screen_.get_point(i, j);
  return ray::from_point_to_point(camera_.position, point_end);
}

color scene::get_color(ray ray) {
  int N = shapes_set.size();
  double t = 0.0;
  int j = 0;
  for (int i = 0; i < N; i++) {
    t = shapes_set[i].intersect(ray);
    if (std::abs(t + 1) > 1e-6) {
      j = i;
      break;
    }
  }
  double_vector bl(0, 0, 0);
  color black(bl);
  if (std::abs(t + 1) < 1e-6) {
    return black;
  }
  double_vector point = ray.direction * t + ray.point_start;
  color amb_color = get_ambient_color(shapes_set[j]);
  color dif_color = get_diffuse_color(shapes_set[j], point);
  color spec_color = get_specular_color(shapes_set[j], point);
  return amb_color + dif_color + spec_color;
}

color scene::get_ambient_color(sphere shape) { return ambient ^ shape.ambient; }

color scene::get_diffuse_color(sphere shape, double_vector point) {
  double_vector normal = shape.normal(point);
  double_vector light_direction = (light_.position - point).get_unit_vector();
  double sk = light_direction & normal;
  return light_.color_ * (shape.diffusion * sk);
}

color scene::get_specular_color(sphere shape, double_vector point) {
  double_vector normal = shape.normal(point);
  double_vector light_direction = (point - light_.position).get_unit_vector();
  double sk = light_direction & normal;
  double_vector reflected = light_direction - normal * 2 * sk;
  double_vector camera_view = (camera_.position - point).get_unit_vector();
  double reflected_sk = reflected & camera_view;
  reflected_sk = std::max(reflected_sk, 0.0);
  return light_.specular_color * light_.specular_koef *
         std::pow(reflected_sk, shape.alpha);
}

color scene::get_color_for_coordinates(int i, int j) {
  ray ray = get_ray(i, j);
  return get_color(ray);
}
