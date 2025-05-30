#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

int main()
{
	for (int i = 0; i < 10; ++i)
	{
		Base *obj = generate();

		std::cout << "Test " << i + 1 << " (pointer): ";
		identify(obj);

		std::cout << "Test " << i + 1 << " (reference): ";
		identify(*obj);

		delete obj;
	}
	return 0;
}