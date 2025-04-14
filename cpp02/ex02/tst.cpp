#include <iostream>

int main()
{
	float a = 5.4;
	int b = 7;

	std::cout << (b = a + a) << std::endl;
}