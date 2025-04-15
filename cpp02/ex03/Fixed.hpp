#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>

class Fixed
{
private:
	int value;
	static const int fractionalBits = 8;

public:
	Fixed(const float floatNum);
	Fixed(const int fixedNum);				
	Fixed(); 				  			  // default constructor
	Fixed(const Fixed &copy); 			  // copy constructor
	Fixed & operator=(const Fixed &copy); // copy assignment constructor
	~Fixed(); 				  			  // destructor

	void setRawBits(const int raw);
	int getRawBits() const;
	
	float toFloat() const;
	int	toInt() const;

	// operator overloads
	// ---comparasiions operators---
	bool operator<(const Fixed& toCompare) const;
	bool operator>(const Fixed& toCompare) const;
	bool operator<=(const Fixed& toCompare) const;
	bool operator>=(const Fixed& toCompare) const;
	bool operator==(const Fixed& toCompare) const;
	bool operator!=(const Fixed& toCompare) const;
	
	// ---arithmetic operators---
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;

	// ---incrememt/decrement operators---
	Fixed operator++(int); // a++
	Fixed operator++(void); // ++a
	Fixed operator--(int); // a--
	Fixed operator--(void); // --a

	// ---desired methods---
	static Fixed& min(Fixed& a, Fixed& c);
	static const Fixed& min(const Fixed& a, const Fixed& c);
	static Fixed& max(Fixed& a, Fixed& c);
	static const Fixed& max(const Fixed& a, const Fixed& c);

};

std::ostream &operator<<(std::ostream &out, const Fixed &value);	

#endif