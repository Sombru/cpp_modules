#include "Fixed.hpp"

Fixed::Fixed(const int fixedNum): fixed_point(0)
{
    fixed_point = fixedNum << fractionalBits;
    std::cout << "Fixed constructor, converting int to fixed point\n";
}

Fixed::~Fixed()
{
    std::cout << "Fixed defualt default destructor\n";
}

Fixed::Fixed(const Fixed &copy): fixed_point(copy.fixed_point) 
{
    std::cout << "Copy constructor(creates a new object"
              << " as a copy of an existing object)\n";
}

Fixed & Fixed::operator=(const Fixed &copy)
{
    std::cout << "Copy assignment constructor"
              << "(An operator that assigns the" 
              << "values of one object to another," 
              << "overwriting the existing values)\n";
    if (this != &copy)
    {
        this->fixed_point = copy.fixed_point;
    }
    return *this;
}

void Fixed::setRawBits(const int raw)
{
    fixed_point = raw;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called\n";
    return this->fixed_point;
}