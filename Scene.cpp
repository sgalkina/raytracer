#include <cmath>
#include <iostream>
#include <vector>
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

MyScreen :: MyScreen (int w, int h, Camera camera, double focus, DoubleVector up) {
	width = w;
	heigth = h;
	point_center = camera.position + camera.direction*focus;
	vector_normal = camera.direction;
	vector_right = (vector_normal % up).get_unit_vector();
	vector_up = (vector_right % vector_normal).get_unit_vector();
}

MyScreen :: MyScreen () {
}

DoubleVector MyScreen :: get_point (int i, int j) {
	int ci = width/2;
	int cj = heigth/2;
	return point_center + vector_right*(i - ci) + vector_up*(j - cj);
}

Scene :: Scene (Camera c, MyScreen sc, std::vector<Sphere> shapes, DoubleVector amb, Light l) {
	camera = c;
	screen = sc;
	shapes_set = shapes;
	ambient = amb;
	light = l;
}

Ray Scene :: get_ray (int i, int j) {
	DoubleVector point_end = screen.get_point(i, j);
	return Ray :: fromAtoB (camera.position, point_end);
}

Color Scene :: get_color (Ray ray) {
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
	DoubleVector bl (0, 0, 0);
	Color black (bl);
	if (std::abs(t + 1) < 1e-6) {
		return black;
	}
	DoubleVector point = ray.direction*t + ray.point_start;
	Color amb_color = get_ambient_color(shapes_set[j]);
	Color dif_color = get_diffuse_color(shapes_set[j], point);
	Color spec_color = get_specular_color(shapes_set[j], point);
	return amb_color + dif_color + spec_color;

}

Color Scene :: get_ambient_color (Sphere shape) {
	return ambient^shape.ambient;
}

Color Scene :: get_diffuse_color (Sphere shape, DoubleVector point) {
	DoubleVector normal = shape.normal(point);
	DoubleVector light_direction = (light.position - point).get_unit_vector();
	double sk = light_direction&normal;
	return light.color*(shape.diffusion*sk);
}

Color Scene :: get_specular_color (Sphere shape, DoubleVector point) {
	DoubleVector normal = shape.normal(point);
	DoubleVector light_direction = (point - light.position).get_unit_vector();
	double sk = light_direction&normal;
	DoubleVector reflected = light_direction - normal*2*sk;
	DoubleVector camera_view = (camera.position - point).get_unit_vector();
	double reflected_sk = reflected&camera_view;
	reflected_sk = std::max(reflected_sk, 0.0);
	return light.specular_color*light.specular_koef*std::pow(reflected_sk, shape.alpha);
}

Color Scene :: get_color_for_coordinates (int i, int j) {
	Ray ray = get_ray(i, j);
	return get_color(ray);
}

