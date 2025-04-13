#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int fixed_point;
	static const int fractionalBits = 8;

public:
	Fixed(const float floatNum);
	Fixed(const int fixedNum);				
	Fixed(); 				  				// default constructor
	Fixed(const Fixed &copy); 				// copy constructor
	Fixed & operator = (const Fixed &copy); // copy assignment constructor
	~Fixed(); 				  				// destructor

	void setRawBits(const int raw);
	int getRawBits() const;

};

#endif