#include "Weapon.hpp"

Weapon::Weapon(std::string const type)
{
	this->type = type;
	std::cout << "Making a " << type << '\n';
}

Weapon::~Weapon()
{
	std::cout << "Destroying " << this->type << " weapon\n";
}

std::string const &Weapon::getType()
{
	return this->type;
}

void Weapon::setType(std::string to_set)
{
	this->type = to_set;
}