#include "HumanB.hpp"
#include "Weapon.hpp"
#include <stdio.h>

HumanB::HumanB(std::string name) // pointer can be null so we dont need to weapon call a constructor here
{
	this->_name = name;
	std::cout << "A " << this->_name << " with no weapon yet" << '\n';
}

HumanB::~HumanB()
{
	std::cout << "A " << this->_name << " armed with " << this->_weapon->getType() << " ended his reign\n";
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void HumanB::attack()
{
	if (!this->_weapon)
	{
		std::cout << this->_name << " has no weapon to attack with!\n";
		return ;
	}
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << '\n';
}	