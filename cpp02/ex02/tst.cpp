#include <iostream>

int main( void ) {
	float a = 0;
	float b( ( 5.05f ) * ( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	return 0;
	}