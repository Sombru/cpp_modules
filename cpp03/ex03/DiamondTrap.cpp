#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
: ClapTrap(name + "_clap_name"), FlagTrap(name), ScavTrap(name), _name(name)
{
	// only one storage for stats is used and because ScavTrap initalizes after FlagTrap
	// it overwrites the stats of FlagTrap and therefore only stats of ScavTrap is used
	_hp = FlagTrap::_hp;
	_mp = ScavTrap::_mp;
	_dmg = FlagTrap::_dmg;

	std::cout << "DiamondTrap constructor called for " << _name << "\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy)
: ClapTrap(copy.get_name() + "_clap_name"), FlagTrap(copy), ScavTrap(copy), _name(copy._name)
{
	set_hp(copy.get_hp());
	set_mp(copy.get_mp());
	set_dmg(copy.get_dmg());
	std::cout << "DiamondTrap copy constructor called for " << this->_name << "\n";
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
	set_hp(copy.get_hp());
	set_mp(copy.get_mp());
	set_dmg(copy.get_dmg());
	std::cout << "Setting stats of " << this->get_name()
			  << " to stats of " << copy.get_name() << '\n';
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called for " << this->_name << "\n";
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am " << this->_name << " and my ClapTrap name is " << ClapTrap::_name << "\n";
}
