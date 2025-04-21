#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FlagTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap
: public FlagTrap, public ScavTrap 
{
private:
	std::string _name;

public:
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &copy);
	DiamondTrap &operator=(const DiamondTrap &copy);
	~DiamondTrap();

	void attack(const std::string &target);
	void whoAmI();

};

#endif