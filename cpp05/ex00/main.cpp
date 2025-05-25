#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b1(1, "Bob");
	
	std::cout << b1 << '\n';

	Bureaucrat b2(45, "Jhon");
	Bureaucrat b3(15, "Mike");

	std::cout << b1 << " || " << b2 << '\n';

	b1.setGrade(69);

	std::cout << b1 << " || " << b2 << '\n';

	b2 = b3;

	std::cout << b3 << " || " << b2 << '\n';
}


	// int i = 0;

	// try
	// {
	// 	if (i == 0)
	// 		throw i;
	// }
	// catch (int i)
	// {
	// 	std::cout << i << std::endl;
	// }
