#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure constructor\n";
}

Cure::Cure(const Cure &copy) : AMateria(copy)
{
	std::cout << "Cure copy constructor\n";
}

Cure &Cure::operator=(const Cure &other)
{
	if (this != &other)
	{
		mType = other.mType;
	}
	std::cout << "Cure assignment operator\n";
	return *this;
}

Cure::~Cure()
{
	std::cout << "Cure destructor\n";
}

AMateria *Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}