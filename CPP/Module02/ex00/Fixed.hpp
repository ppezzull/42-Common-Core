#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int fixedPointValue;
    static const int fractionalBits = 8;

public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed &other);
    Fixed& operator=(const Fixed &other);

    int getRawBits() const;
    void setRawBits(int const raw);
};

#endif
