#include <iostream>
#include "Fixed.hpp"

int main( void ) 
{
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}
	std::cout << "arithmetic operators\n";

	Fixed a, b, c;

	a = 4.1f;
	b = 4;
	c =	1.5f;
	std::cout << (a * b) << '\n';
	std::cout << (a + b) << '\n';
	std::cout << (b - a) << '\n';
	std::cout << (b / 0) << '\n';

	std::cout << "comparasions operators\n";

	std::cout << (a > b) << '\n';
	std::cout << (a < b) << '\n';
	std::cout << (a >= b) << '\n';
	std::cout << (a <= b) << '\n';
	std::cout << (a == b) << '\n';
	std::cout << (a != b) << '\n';


	return 0;
}