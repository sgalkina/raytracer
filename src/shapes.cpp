#include "shapes.h"
#include "ray.h"
#include "vector.h"
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
  double_vector a1 = point_center;
  double_vector a2 = ray.point_start;
  unit_vector d = ray.direction;
  double_vector c = a2 - a1;
  double sqrtD = sqrt((c & d) * (c & d) - (c & c) + radius * radius);
  double cd = c & d;
  double t1 = -cd - sqrtD;
  if (t1 >= 0) {
    return t1;
  }
  return -1;
}

double_vector sphere::normal(double_vector P) {
  double_vector rad_vec = P - point_center;
  if (std::abs(rad_vec.find_length() - radius) > 1e-6) {
    std::cout << "Point is not on sphere" << std::endl;
    return double_vector(0, 0, 0);
  }
  return rad_vec.get_unit_vector();
}
