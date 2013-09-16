#include <iostream>
#include <string.h>
#include <math.h>
#include "RayVector.h"

int main()
{
    typedef RayVector<double> DoubleVector;
    DoubleVector viktor (-1, 2, -3);
    viktor.get_unit_vector().print_coordinates();
    DoubleVector gektor (0, -4, 1);
    std::cout << (viktor & gektor) << std::endl;
    std::cout << "length " << viktor.find_length() << std::endl;
    (viktor % gektor).print_coordinates();
    (viktor * 5).print_coordinates();
    std::string s = "x";
    std::string e = "e";
    while (s.compare(e) != 0) {
        std::cout << "Enter 'e' for exit: ";
        std::cin >> s;
    }
    return 0;
}