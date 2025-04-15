#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed()
{
	this->value = 0;
	std::cout << "Fixed default constructor\n";
}

Fixed::~Fixed()
{
    std::cout << "Fixed defualt destructor\n";
}

Fixed::Fixed(const float floatNum)
{
	value = static_cast<int>(roundf(floatNum * (1 << fractionalBits)));
	std::cout << "float constructor\n";	
}

Fixed::Fixed(const int fixedNum)
{
    value = fixedNum << fractionalBits;
    std::cout << "int constructor\n";
}

Fixed::Fixed(const Fixed &copy): value(copy.value) 
{
    std::cout << "Copy constructor(creates a new object"
              << " as a copy of an existing object)\n";
}

Fixed & Fixed::operator=(const Fixed &copy)
{
    std::cout << "Copy assignment constructor"
              << "(An operator that assigns the" 
              << " values of one object to another," 
              << " overwriting the existing values)\n";
    if (this != &copy)
    {
        this->value = copy.value;
    }
    return *this;
}

void Fixed::setRawBits(const int raw)
{
    value = raw;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called\n";
    return this->value;
}

int Fixed::toInt() const
{
	return this->value >> fractionalBits;
}

float Fixed::toFloat() const
{
	return this->value / static_cast<float>(1 << fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat(); // converts value to float as desired by the subject 
	return out;
}