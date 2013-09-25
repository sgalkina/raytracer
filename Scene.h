class Color {
  DoubleVector color;
  public:
    Color (DoubleVector v);
    Color ();
    DoubleVector get_color();
    Color operator+ (Color other);
    Color operator% (Color other);
    bool operator== (Color other);
};

class Camera {
  DoubleVector position;
  DoubleVector direction;
  public:
    Camera (DoubleVector point_start, DoubleVector point_end);
    Camera ();
    DoubleVector get_position();
    DoubleVector get_direction();
};

class Screen {
  double width;
  double heigth;
  DoubleVector point_center;
  UnitVec vector_up;
  UnitVec vector_right;
  UnitVec vector_normal;
  public:
    Screen (int w, int h, Camera camera, double focus);
    Screen ();
    DoubleVector get_point (int i, int j);
};

class Scene {
  Camera camera;
  Screen screen;
  Sphere sphere;
  public:
    Scene (Camera camera, Screen screen, Sphere sphere);
    Ray get_ray (int i, int j);
    Color get_color (Ray ray);
    Color get_color_for_coordinates (int i, int j);
};

#include "Scene.cpp"