#include "FlagTrap.hpp"

FlagTrap::FlagTrap(std::string name)
: ClapTrap(name)
{
	_hp = 100;
	_mp = 100;
	_dmg = 30;

	std::cout << "FlagTrap(not ClapTrap) constructor\n";
}

FlagTrap::FlagTrap(const FlagTrap &copy)
: ClapTrap(copy.get_name())
{
	set_hp(copy.get_hp());
	set_mp(copy.get_mp());
	set_dmg(copy.get_dmg());
	std::cout << "FlagTrap copy constructor\n";
}

FlagTrap &FlagTrap::operator=(const FlagTrap &copy)
{
	set_hp(copy.get_hp());
	set_mp(copy.get_mp());
	set_dmg(copy.get_dmg());
	std::cout << "Setting stats of " << this->get_name()
			  << " to stats of " << copy.get_name() << '\n';
	return *this;
}

FlagTrap::~FlagTrap()
{
	std::cout << "FlagTrap Destructor\n";
}

void FlagTrap::highFivesGuys()
{
	std::cout << "high five guys, wow. it does literarly nothing\n";
}