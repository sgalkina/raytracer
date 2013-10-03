#ifndef COLOR
#define COLOR

#include "Vector.h"

class Color {
  DoubleVector color;
  public:
    Color (DoubleVector v);
    Color ();
    DoubleVector get_color();
    Color operator+ (Color other);
    Color operator% (Color other);
    bool operator== (Color other);
    DoubleVector decode_to_CImg_format();
};

#endif