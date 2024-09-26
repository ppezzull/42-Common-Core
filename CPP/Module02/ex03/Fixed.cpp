#include "Fixed.hpp"

// Constructors and Destructor
Fixed::Fixed() : fixedPointValue(0) {}

Fixed::Fixed(const int intValue) {
    fixedPointValue = intValue << fractionalBits;
}

Fixed::Fixed(const float floatValue) {
    fixedPointValue = roundf(floatValue * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &other) {
    *this = other;
}

Fixed& Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        this->fixedPointValue = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {}

// Getters and Setters
int Fixed::getRawBits() const {
    return fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    fixedPointValue = raw;
}

float Fixed::toFloat() const {
    return (float)fixedPointValue / (1 << fractionalBits);
}

int Fixed::toInt() const {
    return fixedPointValue >> fractionalBits;
}

// Comparison operators
bool Fixed::operator>(const Fixed &other) const {
    return this->fixedPointValue > other.fixedPointValue;
}

bool Fixed::operator<(const Fixed &other) const {
    return this->fixedPointValue < other.fixedPointValue;
}

bool Fixed::operator>=(const Fixed &other) const {
    return this->fixedPointValue >= other.fixedPointValue;
}

bool Fixed::operator<=(const Fixed &other) const {
    return this->fixedPointValue <= other.fixedPointValue;
}

bool Fixed::operator==(const Fixed &other) const {
    return this->fixedPointValue == other.fixedPointValue;
}

bool Fixed::operator!=(const Fixed &other) const {
    return this->fixedPointValue != other.fixedPointValue;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
    if (other.fixedPointValue != 0)
        return Fixed(this->toFloat() / other.toFloat());
    else {
        std::cerr << "Division by zero" << std::endl;
        return Fixed();
    }
}

// Increment/Decrement operators
Fixed& Fixed::operator++() {
    fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++(*this);
    return temp;
}

Fixed& Fixed::operator--() {
    fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    --(*this);
    return temp;
}

// Min/Max functions
Fixed& Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}

// Insertion operator overload
std::ostream& operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}
