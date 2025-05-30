#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::Base() {}

Base::~Base() {}

Base *generate()
{
	static bool seeded = false;
	if (!seeded)
	{
		std::srand(static_cast<unsigned int>(std::time(0)));
		seeded = true;
	}
	int r = std::rand() % 3;
	if (r == 0)
		return new A;
	else if (r == 1)
		return new B;
	else
		return new C;
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B *>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C *>(p))
		std::cout << "C\n";
	else
		std::cout << "Unknown\n";
}

void identify(Base &p)
{
	// since refernce cant be NULL if we typecast it to it will throw an exeption 
	// by trial and error we will get appropriate type
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A\n";
		return;
	}
	catch(const std::exception& e)
	{
		// std::cerr << e.what();
	}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B\n";
		return;
	}
	catch(const std::exception& e)
	{
		// std::cerr << e.what();
	}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C\n";
		return;
	}
	catch(const std::exception& e)
	{
		// std::cerr << e.what();
	}
	
	std::cout << "Unknown\n";
}