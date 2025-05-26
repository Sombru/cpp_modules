#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice constructor\n";
}

Ice::Ice(const Ice &copy) : AMateria(copy)
{
	std::cout << "Ice copy constructor\n";
}

Ice &Ice::operator=(const Ice &other)
{
	if (this != &other)
	{
		mType = other.mType;
	}
	std::cout << "Ice assignment operator\n";
	return *this;
}

Ice::~Ice()
{
	std::cout << "Ice destructor\n";
}

AMateria *Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}