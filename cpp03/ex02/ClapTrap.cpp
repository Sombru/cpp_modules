#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
: _name(name), _hp(10), _mp(10), _dmg(0) 
{
	std::cout << "ClapTrap named " << _name << " arrives!\n";
}

ClapTrap::ClapTrap(const ClapTrap &copy)
: _name(copy.get_name() + "_clone"), _hp(copy.get_hp()), _mp(copy.get_mp()), _dmg(copy.get_dmg())
{
	std::cout << "Cloning a ClapTrap named " << copy.get_name() << " into " << _name << "\n";	
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	set_hp(copy.get_hp());
	set_mp(copy.get_mp());
	set_dmg(copy.get_dmg());
	std::cout << "Setting stats of " << this->get_name()
			  << " to stats of " << copy.get_name() << '\n';
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap named " << _name << " is destroyed\n";
}

std::string ClapTrap::get_name() const
{
	return this->_name;
}

unsigned int ClapTrap::get_hp() const
{
	return this->_hp;
}

unsigned int ClapTrap::get_mp() const
{
	return this->_mp;
}

unsigned int ClapTrap::get_dmg() const
{
	return this->_dmg;
}

void ClapTrap::set_hp(unsigned int hp)
{
	this->_hp = hp;
}

void ClapTrap::set_mp(unsigned int mp)
{
	this->_mp = mp;
}

void ClapTrap::set_dmg(unsigned int dmg)
{
	this->_dmg = dmg;
}

void ClapTrap::attack(const std::string &target)
{
	std::cout << "ClapTrap " << get_name() 
			  << " attacks " << target
			  << " causing " << get_dmg()
			  << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > _hp)
		set_hp(0);
	else
		set_hp(_hp - amount);
	std::cout << "ClapTrap " << get_name()
	<< " takes " << amount
	<< " damage, he has " << _hp
	<< " hp left\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	set_hp(_hp + amount);
	std::cout << "ClapTrap " << get_name()
			  << " heals " << amount
			  << " of hp, he has" << _hp
			  << " hp now\n";
}

void ClapTrap::check()
{
	std::cout << "ClapTrap Stats:\n"
			  << "Name: " << get_name() << '\n'
			  << "HP: " << get_hp() << '\n'
			  << "MP: " << get_mp() << '\n'
			  << "Damage: " << get_dmg() << '\n';
}
