#pragma once
#include <cmath>
#include <iostream>

template <typename T> class ray_vector {
public:
  T x;
  T y;
  T z;
  ray_vector(T a, T b, T c);
  ray_vector();
  void print_coordinates();
  ray_vector operator+(ray_vector another);
  ray_vector operator-(ray_vector another);
  T operator&(ray_vector another);
  ray_vector operator%(ray_vector another);
  ray_vector operator*(T number);
  ray_vector operator^(ray_vector another);
  bool operator==(ray_vector another);
  double find_length();
  ray_vector get_unit_vector();
};

typedef ray_vector<double> double_vector;
typedef double_vector unit_vector;

template <typename T> ray_vector<T>::ray_vector(T a, T b, T c) {
  x = a;
  y = b;
  z = c;
}

template <typename T> ray_vector<T>::ray_vector() {
  x = 0;
  y = 0;
  z = 0;
}

template <typename T> void ray_vector<T>::print_coordinates() {
  std::cout << "X: " << x << std::endl;
  std::cout << "Y: " << y << std::endl;
  std::cout << "Z: " << z << std::endl;
  std::cout << std::endl;
}

template <typename T>
ray_vector<T> ray_vector<T>::operator+(ray_vector<T> another) {
  return ray_vector<T>(x + another.x, y + another.y, z + another.z);
}

template <typename T>
ray_vector<T> ray_vector<T>::operator-(ray_vector<T> another) {
  return ray_vector<T>(x - another.x, y - another.y, z - another.z);
}

template <typename T> T ray_vector<T>::operator&(ray_vector<T> another) {
  T result = x * another.x + y * another.y + z * another.z;
  return result;
}

template <typename T>
ray_vector<T> ray_vector<T>::operator%(ray_vector<T> another) {
  return ray_vector<T>(y * another.z - z * another.y,
                       z * another.x - x * another.z,
                       x * another.y - y * another.x);
}

template <typename T>
ray_vector<T> ray_vector<T>::operator^(ray_vector<T> another) {
  return ray_vector<T>(x * another.x, y * another.y, z * another.z);
}

template <typename T> bool ray_vector<T>::operator==(ray_vector<T> another) {
  return (std::abs(x - another.x) < 1e-6) && (std::abs(y - another.y) < 1e-6) &&
         (std::abs(z - another.z) < 1e-6);
}

template <typename T> ray_vector<T> ray_vector<T>::operator*(T number) {
  return ray_vector<T>(x * number, y * number, z * number);
}

template <typename T> double ray_vector<T>::find_length() {
  return sqrt(x * x + y * y + z * z);
}

template <typename T> ray_vector<T> ray_vector<T>::get_unit_vector() {
  double length = find_length();
  return ray_vector<T>(x / length, y / length, z / length);
}
