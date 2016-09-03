#include "light.h"
#include "colors.h"
#include "vector.h"

light::light(double_vector p, double_vector c, color s_c, double s_k)
    : position_(p), color_(c), specular_color_(s_c), specular_coef_(s_k) {}

light::light() {}

double_vector light::position() const { return position_; }
double_vector light::colour() const { return color_; }
color light::specular_color() const { return specular_color_; }
double light::specular_coef() const { return specular_coef_; }
