#include "ScavTrap.hpp"


ScavTrap::ScavTrap(std::string name)
: ClapTrap(name)
{
	_hp = 100;
	_mp = 50;
	_dmg = 20;
	std::cout << "ScavTrap(not ClapTrap) constructor\n";
}

ScavTrap::ScavTrap(const ScavTrap &copy)
: ClapTrap(copy.get_name())
{
	set_hp(copy.get_hp());
	set_mp(copy.get_mp());
	set_dmg(copy.get_dmg());
	std::cout << "ScavTrap copy constructor\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
	set_hp(copy.get_hp());
	set_mp(copy.get_mp());
	set_dmg(copy.get_dmg());
	std::cout << "Setting stats of " << this->get_name()
			  << " to stats of " << copy.get_name() << '\n';
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap named " << _name << " is destroyed\n";

}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now gatekeeper... this changes nothing its jut how it is now\n";
}


void ScavTrap::attack(const std::string &target)
{
	std::cout << "ScavTrap " << get_name() 
			  << " attacks " << target
			  << " causing " << get_dmg()
			  << " points of damage!\n";
}