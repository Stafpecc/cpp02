#include "Fixed.hpp"

Fixed::Fixed(): _fixedPoint(0) {}
	
Fixed::Fixed(const Fixed& anotherClass) { *this = anotherClass; }

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        this->_fixedPoint = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const { return this->_fixedPoint; }

void Fixed::setRawBits(int const raw) { this->_fixedPoint = raw; }
