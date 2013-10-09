#include <cmath>
#include <iostream>
#include "Vector.h"
#include "Ray.h"
#include "Shapes.h"
#include "Scene.h"
#include "Colors.h"
#include "Light.h"

Camera :: Camera (DoubleVector point_start, DoubleVector point_end) {
	position = point_start;
	direction = (point_end - point_start).get_unit_vector();
}

Camera :: Camera () {
}

MyScreen :: MyScreen (int w, int h, Camera camera, double focus) {
	width = w;
	heigth = h;
	point_center = camera.position + camera.direction*focus;
	vector_normal = camera.direction;
	DoubleVector vector_up_false (0, 0, 1); // todo: rewrite
	vector_right = (vector_normal % vector_up_false).get_unit_vector();
	vector_up = (vector_right % vector_normal).get_unit_vector();
}

MyScreen :: MyScreen () {
}

DoubleVector MyScreen :: get_point (int i, int j) {
	int ci = width/2;
	int cj = heigth/2;
	return point_center + vector_right*(i - ci) + vector_up*(j - cj);
}

Scene :: Scene (Camera c, MyScreen sc, Sphere sp, DoubleVector amb, Light l) {
	camera = c;
	screen = sc;
	sphere = sp;
	ambient = amb;
	light = l;
}

Ray Scene :: get_ray (int i, int j) {
	DoubleVector point_end = screen.get_point(i, j);
	return Ray :: fromAtoB (camera.position, point_end);
}

Color Scene :: get_color (Ray ray) {
	double t = sphere.intersect(ray);
	DoubleVector point = ray.direction*t + ray.point_start;
	DoubleVector bl (0, 0, 0);
	Color black (bl);
	if (std::abs(t + 1) < 1e-6) {
		return black;
	}
	Color dif_color = get_diffuse_color(point);
	Color amb_color = get_ambient_color();
	return dif_color + amb_color;

}

Color Scene :: get_ambient_color () {
	return ambient^sphere.ambient;
}

Color Scene :: get_diffuse_color (DoubleVector point) {
	DoubleVector normal = sphere.normal(point);
	DoubleVector light_direction = (light.position - point).get_unit_vector();
	double sk = light_direction&normal;
	if (sk < 1e-8 ) {sk = 0;}
	return light.color*(sphere.diffusion*(sk));
}

Color Scene :: get_color_for_coordinates (int i, int j) {
	Ray ray = get_ray(i, j);
	return get_color(ray);
}

