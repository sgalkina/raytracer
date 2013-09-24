Camera :: Camera (DoubleVector point_start, DoubleVector point_end) {
	position = point_start;
	direction = (point_end - point_start).get_unit_vector();
}

DoubleVector Camera :: get_position () {
	return position;
}

DoubleVector Camera :: get_direction () {
	return direction;
}

Screen :: Screen (int w, int h, Camera camera, double focus) {
	width = w;
	heigth = h;
	point_center = camera.get_position() + camera.get_direction()*focus;
}