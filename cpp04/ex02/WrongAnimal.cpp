#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Default animal constructor\n";
}

WrongAnimal::WrongAnimal(const std::string type)
: mType(type)
{
	std::cout << "WrongAnimal constructor for " << type << "\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
: mType(copy.mType)
{
	std::cout << "WrongAnimal copy constructor for " << copy.mType << "\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
	mType = copy.mType;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor\n";
}

std::string WrongAnimal::getType() const
{
	return this->mType;
}

void WrongAnimal::makeSound() const
{
	std::cout << "I am a wrong_animal *avarage wrong_animal sounds*\n";
}