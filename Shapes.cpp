#include <cmath>
#include "Vector.h"
#include "Ray.h"
#include "Shapes.h"
#include "Scene.h"

Sphere :: Sphere (double radius_len, DoubleVector point, DoubleVector amb, double dif, double al)
	{
		radius = radius_len;
		point_center = point;
        ambient = amb;
        diffusion = dif;
        alpha = al;
	}

Sphere :: Sphere ()
    {
    }

double Sphere :: intersect (Ray ray)
    {
    	DoubleVector a1 = point_center;
    	DoubleVector a2 = ray.point_start;
    	UnitVec d = ray.direction;
    	DoubleVector c = a2 - a1;
    	double sqrtD = sqrt((c&d)*(c&d) - (c&c) + radius*radius);
    	double cd = c&d;
    	double t1 = -cd - sqrtD;
    	if (t1 >= 0) {
    		return t1;
    	}
    	return -1;
    }

DoubleVector Sphere :: normal (DoubleVector P) 
	{
		DoubleVector rad_vec = P - point_center;
		if ( std::abs(rad_vec.find_length() - radius) > 1e-6) {
			std::cout << "Point is not on sphere" << std::endl;
			DoubleVector vec (0, 0, 0);
			return vec;
		}
		else {
			return rad_vec.get_unit_vector()*(radius + 1) - P;
		}
	}