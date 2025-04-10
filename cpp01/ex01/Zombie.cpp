#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "An unnamed zombie was created\n";
}

Zombie::Zombie(std::string name)
{
	if (name.empty())
	{
		name = "Regular everyday zombie";
	}
	std::cout << "Making a zombie called " << name << '\n';
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << this->name << " has starved due to lack of brainz\n";
}

void Zombie::_setName(std::string name)
{
	this->name = name;
}

std::string Zombie::_getNanme()
{
	return this->name;
}

void Zombie::announce()
{
	std::cout << _getNanme() << ": BraiiiiiiinnnzzzZ...\n"; 
}