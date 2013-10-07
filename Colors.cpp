#include "Vector.h"
#include "Colors.h"

Color :: Color (DoubleVector v) {
	color = v;
}

Color :: Color () {

}

DoubleVector Color :: get_color () {
	return color;
}

Color Color :: operator+ (Color other) {
	return color + other.get_color();
}

Color Color :: operator^ (Color other) {
	return color ^ other.get_color();
}

bool Color :: operator== (Color other) {
	return color == other.get_color();
}

DoubleVector Color :: decode_to_CImg_format()
{
    return color*255;
}