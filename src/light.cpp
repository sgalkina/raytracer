#include "colors.h"
#include "light.h"
#include "vector.h"

light::light(double_vector p, double_vector c, color s_c, double s_k) {
  position = p;
  color_ = c;
  specular_color = s_c;
  specular_koef = s_k;
}

light::light() {}
