#include "Array.hpp"
#include <iostream>
#include <string>

int main()
{
	Array<int> a;
	std::cout << "Default size: " << a.getSize() << '\n';

	Array<int> b(5);
	for (unsigned int i = 0; i < b.getSize(); ++i)
		b[i] = i * 10;

	std::cout << "Array b: ";
	for (unsigned int i = 0; i < b.getSize(); ++i)
		std::cout << b[i] << " ";
	std::cout << '\n';

	Array<int> c(b);
	std::cout << "Copied array c: ";
	for (unsigned int i = 0; i < c.getSize(); ++i)
		std::cout << c[i] << " ";
	std::cout << '\n';

	Array<int> d;
	d = b;
	std::cout << "Assigned array d: ";
	for (unsigned int i = 0; i < d.getSize(); ++i)
		std::cout << d[i] << " ";
	std::cout << '\n';

	Array<std::string> s(3);
	s[0] = "hello";
	s[1] = "template";
	s[2] = "array";
	std::cout << "String array: ";
	for (unsigned int i = 0; i < s.getSize(); ++i)
		std::cout << s[i] << " ";
	std::cout << '\n';

	try
	{
		std::cout << "Accessing out of range: ";
		std::cout << b[10] << '\n';
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << '\n';
	}

	return 0;
}