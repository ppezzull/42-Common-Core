#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
    const Fixed x;
    const Fixed y;

public:
    // Default constructor
    Point();

    // Constructor with two float arguments
    Point(const float x, const float y);

    // Copy constructor
    Point(const Point &other);

    // Assignment operator overload
    Point& operator=(const Point &other);

    // Destructor
    ~Point();

    // Getters for x and y
    Fixed getX() const;
    Fixed getY() const;
};

#endif
