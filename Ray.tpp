Ray :: Ray (DoubleVector point, NVec rayvector)
    {
        point_start = point;
        direction = rayvector;
    }

Ray Ray :: getRayFromPointAndDirection (DoubleVector point, DoubleVector rayvector) {
    return Ray(point, rayvector.get_unit_vector());
}

Ray Ray :: getRayFromTwoPoints (DoubleVector point_start, DoubleVector point_end) {
    DoubleVector point = point_start;
    DoubleVector direction = point_end - point_start;
    return getRayFromPointAndDirection(point, direction);
}

// Point<T> Ray<T> :: apply (T t)
//     {
//         Point<T> end_vector = (unit_vector*t).get_coordinates();
//         Point<T> end_point;
//         end_point.x = start_point.x + end_vector.x;
//         end_point.y = start_point.y + end_vector.y;
//         end_point.z = start_point.z + end_vector.z;
//         return end_point;
//     }