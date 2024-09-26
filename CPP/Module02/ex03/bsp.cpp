#include "bsp.hpp"

Fixed triangleArea(Point const &p1, Point const &p2, Point const &p3) {
    Fixed area = (p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat())) +
                 (p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat())) +
                 (p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat()));
    if (area.toFloat() < 0)
        return area * Fixed(-1);
    return area / Fixed(2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed totalArea = triangleArea(a, b, c);
    Fixed area1 = triangleArea(point, b, c);
    Fixed area2 = triangleArea(a, point, c);
    Fixed area3 = triangleArea(a, b, point);
    Fixed sumOfAreas = area1 + area2 + area3;
    return totalArea == sumOfAreas;
}
