#ifndef SCENE
#define SCENE

#include "Vector.h"
#include "Ray.h"
#include "Shapes.h"
#include "Colors.h"

class Camera {
  DoubleVector position;
  DoubleVector direction;
  public:
    Camera (DoubleVector point_start, DoubleVector point_end);
    Camera ();
    DoubleVector get_position();
    DoubleVector get_direction();
};

class Screen1 {
  double width;
  double heigth;
  DoubleVector point_center;
  UnitVec vector_up;
  UnitVec vector_right;
  UnitVec vector_normal;
  public:
    Screen1 (int w, int h, Camera camera, double focus);
    Screen1 ();
    DoubleVector get_point (int i, int j);
};

class Scene {
  Camera camera;
  Screen1 screen;
  Sphere sphere;
  public:
    Scene (Camera camera, Screen1 screen, Sphere sphere);
    Ray get_ray (int i, int j);
    Color get_color (Ray ray);
    Color get_color_for_coordinates (int i, int j);
};

#endif