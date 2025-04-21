#ifndef FLAGTRAP_HPP
# define FLAGTRAP_HPP

#include "ClapTrap.hpp"

class FlagTrap
: virtual public ClapTrap
{
private:
	
public:
	FlagTrap(std::string name);
	FlagTrap(const FlagTrap &copy);
	FlagTrap &operator=(const FlagTrap &copy);
	~FlagTrap();

	void highFivesGuys(void);
	
};

#endif