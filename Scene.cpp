#include <cmath>
#include "Vector.h"
#include "Ray.h"
#include "Shapes.h"
#include "Scene.h"
#include "Colors.h"

Camera :: Camera (DoubleVector point_start, DoubleVector point_end) {
	position = point_start;
	direction = (point_end - point_start).get_unit_vector();
}

Camera :: Camera () {
}

DoubleVector Camera :: get_position () {
	return position;
}

DoubleVector Camera :: get_direction () {
	return direction;
}

Screen1 :: Screen1 (int w, int h, Camera camera, double focus) {
	width = w;
	heigth = h;
	point_center = camera.get_position() + camera.get_direction()*focus;
	vector_normal = camera.get_direction();
	DoubleVector vector_up_false (0, 0, 1); // todo: rewrite
	vector_right = (vector_normal % vector_up_false).get_unit_vector();
	vector_up = (vector_right % vector_normal).get_unit_vector();
}

Screen1 :: Screen1 () {
}

DoubleVector Screen1 :: get_point (int i, int j) {
	int ci = width/2;
	int cj = heigth/2;
	return point_center + vector_right*(i - ci) + vector_up*(j - cj);
}

Scene :: Scene (Camera c, Screen1 sc, Sphere sp) {
	camera = c;
	screen = sc;
	sphere = sp;
}

Ray Scene :: get_ray (int i, int j) {
	DoubleVector point_end = screen.get_point(i, j);
	return Ray :: fromAtoB (camera.get_position(), point_end);
}

Color Scene :: get_color (Ray ray) {
	double t = sphere.intersect(ray);
	DoubleVector wh (1, 1, 1);
	Color white (wh);
	DoubleVector bl (0, 0, 0);
	Color black (bl);
	if (std::abs(t + 1) < 1e-6) {
		return white;
	}	
	return black;
}

Color Scene :: get_color_for_coordinates (int i, int j) {
	Ray ray = get_ray(i, j);
	return get_color(ray);
}

