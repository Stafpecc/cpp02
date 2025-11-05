#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(): _fixedPoint(0) { std::cout << "Default constructor called" << std::endl; }
	
Fixed::Fixed(const Fixed& anotherClass) {
    std::cout << "Copy constructor called" << std::endl;
    *this = anotherClass;
}

Fixed& Fixed::operator=(const Fixed& anotherClass) {
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
