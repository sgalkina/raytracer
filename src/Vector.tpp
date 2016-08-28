#include <cmath>
#include <iostream>

template <typename T> RayVector<T>::RayVector(T a, T b, T c) {
  x = a;
  y = b;
  z = c;
}

template <typename T> RayVector<T>::RayVector() {
  x = 0;
  y = 0;
  z = 0;
}

template <typename T> void RayVector<T>::print_coordinates() {
  std::cout << "X: " << x << std::endl;
  std::cout << "Y: " << y << std::endl;
  std::cout << "Z: " << z << std::endl;
  std::cout << std::endl;
}

template <typename T>
RayVector<T> RayVector<T>::operator+(RayVector<T> another) {
  return RayVector<T>(x + another.x, y + another.y, z + another.z);
}

template <typename T>
RayVector<T> RayVector<T>::operator-(RayVector<T> another) {
  return RayVector<T>(x - another.x, y - another.y, z - another.z);
}

template <typename T> T RayVector<T>::operator&(RayVector<T> another) {
  T result = x * another.x + y * another.y + z * another.z;
  return result;
}

template <typename T>
RayVector<T> RayVector<T>::operator%(RayVector<T> another) {
  return RayVector<T>(y * another.z - z * another.y,
                      z * another.x - x * another.z,
                      x * another.y - y * another.x);
}

template <typename T>
RayVector<T> RayVector<T>::operator^(RayVector<T> another) {
  return RayVector<T>(x * another.x, y * another.y, z * another.z);
}

template <typename T> bool RayVector<T>::operator==(RayVector<T> another) {
  return (std::abs(x - another.x) < 1e-6) && (std::abs(y - another.y) < 1e-6) &&
         (std::abs(z - another.z) < 1e-6);
}

template <typename T> RayVector<T> RayVector<T>::operator*(T number) {
  return RayVector<T>(x * number, y * number, z * number);
}

template <typename T> double RayVector<T>::find_length() {
  return sqrt(x * x + y * y + z * z);
}

template <typename T> RayVector<T> RayVector<T>::get_unit_vector() {
  double length = find_length();
  return RayVector<T>(x / length, y / length, z / length);
}
