class Camera {
	DoubleVector position;
	DoubleVector direction;
  public:
  	Camera (DoubleVector point_start, DoubleVector point_end);
  	DoubleVector get_position();
  	DoubleVector get_direction();
};

class Screen {
	double width;
	double heigth;
	DoubleVector point_center;
  public:
  	Screen (int w, int h, Camera camera, double focus);
};

class Scene {

};

#include "Scene.cpp"