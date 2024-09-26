#include <iostream>
#include "Point.hpp"
#include "bsp.hpp"

int main() {
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    Point inside(2, 2); // A point inside the triangle
    Point outside(10, 10); // A point outside the triangle
    Point onEdge(0, 5); // A point on the edge of the triangle

    std::cout << "Point inside the triangle: " << bsp(a, b, c, inside) << std::endl;
    std::cout << "Point outside the triangle: " << bsp(a, b, c, outside) << std::endl;
    std::cout << "Point on the edge of the triangle: " << bsp(a, b, c, onEdge) << std::endl;

    return 0;
}
