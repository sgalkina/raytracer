template < typename T > 
Ray<T> :: Ray (Point<T> startpoint, RayVector<T> rayvector)
    {
        point = startpoint;
        direction = rayvector;
    }
