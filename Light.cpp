#include "Light.h"
#include "Colors.h"

Light :: Light (DoubleVector p, DoubleVector c, Color s_c, double s_k) {
	position = p;
	color = c;
	specular_color = s_c;
	specular_koef = s_k;
}

Light :: Light () {
}