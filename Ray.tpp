template < typename T > 
Ray<T> :: Ray (RayVector<T> rayvector)
    {
        unit_vector = rayvector.get_unit_vector();
        Point<T> some_point = rayvector.get_coordinates();
        start_point.x = some_point.x; 
        start_point.y = some_point.y; 
        start_point.z = some_point.z;
    }

template < typename T > 
Ray<T> :: Ray (Point<T> A, Point<T> B)
    {
        RayVector<T> ray_vector (B.x - A.x, B.y - A.y, B.z - A.z);
        unit_vector = ray_vector.get_unit_vector();
        start_point.x = A.x; 
        start_point.y = A.y; 
        start_point.z = A.z;
    }

template < typename T > 
Point<T> Ray<T> :: apply (T t)
    {
        Point<T> end_vector = (unit_vector*t).get_coordinates();
        Point<T> end_point;
        end_point.x = start_point.x + end_vector.x;
        end_point.y = start_point.y + end_vector.y;
        end_point.z = start_point.z + end_vector.z;
        return end_point;
    }