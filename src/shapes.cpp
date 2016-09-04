#include "shapes.h"
#include "ray.h"
#include "vector.h"
#include <cassert>
#include <cmath>

sphere::sphere(double radius_len, double_vector point, double_vector amb,
               double dif, double al) {
  radius = radius_len;
  point_center = point;
  ambient = amb;
  diffusion = dif;
  alpha = al;
}

sphere::sphere() {}

double sphere::intersect(ray ray) {
  double_vector c = ray.point_start() - point_center;
  double cd = c & ray.direction();
  double t1 = -cd - sqrt(cd * cd - (c & c) + radius * radius);
  if (t1 >= 0)
    return t1;
  return -1;
}

double_vector sphere::normal(double_vector P) {
  double_vector rad_vec = P - point_center;
  assert(std::abs(rad_vec.find_length() - radius) <= 1e-6 &&
         "Point is not on the sphere");
  return rad_vec.get_unit_vector();
}

void sphere::print() const {
  std::cout << "Radius: " << radius << "\n"
            << "Center: ";
  point_center.print_coordinates();
  std::cout << "Ambient: ";
  ambient.print_coordinates();
  std::cout << "Diffusion: " << diffusion << "\n"
            << "Alpha: " << alpha << "\n"
            << std::endl;
}
