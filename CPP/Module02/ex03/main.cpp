#include "Point.hpp"
#include "bsp.hpp"

int main(int argc, char** argv) {
    if (argc != 9) {
        std::cerr << "Usage: " << argv[0] << " x1 y1 x2 y2 x3 y3 px py" << std::endl;
        return 1;
    }

    Point a(std::atof(argv[1]), std::atof(argv[2]));
    Point b(std::atof(argv[3]), std::atof(argv[4]));
    Point c(std::atof(argv[5]), std::atof(argv[6]));
    Point p(std::atof(argv[7]), std::atof(argv[8]));

    if (bsp(a, b, c, p)) {
        std::cout << "The point is in the triangle." << std::endl;
    } else {
        std::cout << "The point is not in the triangle." << std::endl;
    }

    return 0;
}
