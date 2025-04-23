#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Default animal constructor\n";
}

Animal::Animal(const std::string type)
: mType(type)
{
	std::cout << "Animal constructor for " << type << "\n";
}

Animal::Animal(const Animal &copy)
: mType(copy.mType)
{
	std::cout << "Animal copy constructor for " << copy.mType << "\n";
}

Animal &Animal::operator=(const Animal &copy)
{
	mType = copy.mType;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor\n";
}

std::string Animal::getType() const
{
	return this->mType;
}

void Animal::makeSound() const
{
	std::cout << "I am an animal *average animal sounds*\n";
}