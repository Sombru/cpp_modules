#include "Dog.hpp"

Dog::Dog()
: Animal("dog")
{
	std::cout << "Dog default constructor\n";
}

Dog::Dog(const Dog &copy)
: Animal(copy.getType())
{
	std::cout << "Dog copy constructor\n";
}

Dog &Dog::operator=(const Dog &copy)
{
	Animal::mType = copy.getType();
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor\n";
}

void Dog::makeSound() const
{
	std::cout << "I am a dog *bark bark*\n";
}
