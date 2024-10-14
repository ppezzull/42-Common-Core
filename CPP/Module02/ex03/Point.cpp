#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float xValue, const float yValue) : x(xValue), y(yValue) {}

Point::Point(const Point &other) : x(other.getX()), y(other.getY()) {}

Point::~Point() {}

Fixed Point::getX() const {
    return x;
}

Fixed Point::getY() const {
    return y;
}

Point& Point::operator=(const Point &other) {
    (void) other;
    return *this;
}
