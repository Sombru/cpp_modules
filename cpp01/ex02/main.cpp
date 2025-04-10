#include <iostream>
#include <string>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	
	// reference - must ne initialized when declared, cannot be null, 
	// accesed directly without need to collapse the pointer
	std::string &stringREF = str;
	
	//pointer
	std::string *stringPTR = &str;

	std::cout << &stringREF << '\n'; // adresses
	std::cout << &stringPTR << '\n'; // adresses

	std::cout << stringREF << '\n';
	std::cout << *stringPTR << '\n';
}