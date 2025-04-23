#include "Cat.hpp"

Cat::Cat()
: Animal("cat"), brain(new Brain)
{
	std::cout << "Cat default constructor\n";
}

Cat::Cat(const Cat &copy)
: Animal(copy.getType())
{
	std::cout << "Cat copy constructor\n";
}

Cat &Cat::operator=(const Cat &copy)
{
	Animal::mType = copy.getType();
	return *this;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor\n";
}

Brain* Cat::getBrain()
{
	return this->brain;
}

void Cat::makeSound() const
{
	std::cout << "I am a cat *mew mew*\n";
}