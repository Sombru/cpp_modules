#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int value;
	static const int fractionalBits = 8;

public:
	Fixed(); 				  				// default constructor
	Fixed(const Fixed &copy); 				// copy constructor
	Fixed & operator=(const Fixed &copy); // copy assignment constructor
	~Fixed(); 				  				// destructor

	void setRawBits(const int raw);
	int getRawBits() const;

};

#endif