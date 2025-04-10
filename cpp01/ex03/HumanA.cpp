#include "HumanA.hpp"
#include "Weapon.hpp"
												// this is member initializer list 
HumanA::HumanA(std::string name, Weapon &weapon): _weapon(weapon)// reference cant be null so we call weapon constructor 
{
	this->_name = name;
	std::cout << "A " << this->_name << " with " << weapon.getType() << '\n';
}

HumanA::~HumanA()
{
	std::cout << "A " << this->_name <<  " armed with " << this->_weapon.getType() << " ended his reign\n";
}

void HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << '\n';
}	