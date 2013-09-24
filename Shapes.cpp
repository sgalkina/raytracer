Sphere :: Sphere (double radius_len, DoubleVector point)
	{
		radius = radius_len;
		point_center = point;
	}

double Sphere :: intersect (Ray ray)
    {
    	DoubleVector a1 = point_center;
    	DoubleVector a2 = ray.get_start_point();
    	UnitVec d = ray.get_direction();
    	DoubleVector c = a2 - a1;
    	double sqrtD = sqrt((c&d)*(c&d) - c.find_length() + radius*radius);
    	double cd = c&d;
    	double t1 = -cd - sqrtD;
    	if (t1 >= 0) {
    		return t1;
    	}
    	else {
    		double t2 = -cd + sqrtD;
    		if (t2 >= 0) {
    			return t2;
    		}
    	}
    	return -1;
    }

DoubleVector Sphere :: normal (DoubleVector P) 
	{
		DoubleVector rad_vec = P - point_center;
		rad_vec.print_coordinates();
		std::cout << rad_vec.find_length() << std::endl;
		if ( rad_vec.find_length() != radius) {
			std::cout << "Point is not on sphere" << std::endl;
			DoubleVector vec (0, 0, 0);
			return vec;
		}
		else {
			return rad_vec.get_unit_vector()*(radius + 1) - P;
		}
	}