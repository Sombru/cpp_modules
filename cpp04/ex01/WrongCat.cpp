#include "WrongCat.hpp"

WrongCat::WrongCat()
: WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor\n";
}

WrongCat::WrongCat(const WrongCat &copy)
: WrongAnimal(copy.getType())
{
	std::cout << "WrongCat copy constructor\n";
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
	WrongAnimal::mType = copy.getType();
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor\n";
}

void WrongCat::makeSound() const
{
	std::cout << "I am a WrongCat *wrong_mew wrong_mew*\n";
}