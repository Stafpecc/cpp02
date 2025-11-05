#include "Fixed.hpp"
#include <iostream>
#include <math.h>

Fixed::Fixed(): _fixedPoint(0) { std::cout << "Default constructor called" << std::endl; }
	
Fixed::Fixed(const Fixed& anotherClass) {
    std::cout << "Copy constructor called" << std::endl;
    *this = anotherClass;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPoint = value << this->_fractionalBit;
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPoint = roundf(value * (1 << this->_fractionalBit));
}

Fixed& Fixed::operator=(const Fixed& anotherClass)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &anotherClass)
        this->_fixedPoint = anotherClass.getRawBits();
    return *this;
}   

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPoint;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixedPoint = raw;
}

float Fixed::toFloat(void) const {
    return (float)this->_fixedPoint / (1 << this->_fractionalBit);
}

int Fixed::toInt(void) const {
    return this->_fixedPoint >> this->_fractionalBit;
}

std::ostream& operator<<(std::ostream& os, Fixed const& anotherClass)
{
    os << anotherClass.toFloat();
    return os;
}

bool Fixed::operator>(const Fixed& anotherClass) const { return this->toFloat() > anotherClass.toFloat(); }

bool Fixed::operator<(const Fixed& anotherClass) const { return this->toFloat() < anotherClass.toFloat(); }

bool Fixed::operator>=(const Fixed& anotherClass) const { return this->toFloat() >= anotherClass.toFloat(); }

bool Fixed::operator<=(const Fixed& anotherClass) const { return this->toFloat() <= anotherClass.toFloat(); }

bool Fixed::operator==(const Fixed& anotherClass) const { return this->toFloat() == anotherClass.toFloat(); }

bool Fixed::operator!=(const Fixed& anotherClass) const { return this->toFloat() != anotherClass.toFloat(); }

Fixed Fixed::operator+(const Fixed& anotherClass) const { return this->toFloat() + anotherClass.toFloat(); }

Fixed Fixed::operator-(const Fixed& anotherClass) const { return this->toFloat() - anotherClass.toFloat(); }

Fixed Fixed::operator*(const Fixed& anotherClass) const { return this->toFloat() * anotherClass.toFloat(); }

Fixed Fixed::operator/(const Fixed& anotherClass) const { return this->toFloat() / anotherClass.toFloat(); }

Fixed& Fixed::max(Fixed &a, Fixed &b) { return (a >= b) ? a : b; }

Fixed& Fixed::min(Fixed &a, Fixed &b) { return (a <= b) ? a : b; }

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) { return (a >= b) ? a : b; }

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) { return (a <= b) ? a : b; }

Fixed& Fixed::operator++() {
    this->_fixedPoint++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    this->_fixedPoint++;
    return tmp;
}

Fixed& Fixed::operator--() {
    this->_fixedPoint--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    this->_fixedPoint--;
    return tmp;
}
