#include "Fixed.hpp"

Fixed::Fixed(): value(0)
{
    std::cout << "Fixed default constructor\n";
}

Fixed::~Fixed()
{
    std::cout << "Fixed defualt default destructor\n";
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