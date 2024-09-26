#include "Point.hpp"

// Default constructor initializes x and y to 0
Point::Point() : x(0), y(0) {}

// Constructor with two float arguments
Point::Point(const float xValue, const float yValue) : x(xValue), y(yValue) {}

// Copy constructor
Point::Point(const Point &other) : x(other.getX()), y(other.getY()) {}

// Destructor
Point::~Point() {}

// Getter for x
Fixed Point::getX() const {
    return x;
}

// Getter for y
Fixed Point::getY() const {
    return y;
}
