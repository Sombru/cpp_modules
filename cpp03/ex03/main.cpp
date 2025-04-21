#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FlagTrap.hpp"
#include "DiamondTrap.hpp"

#define GURADS std::cout << "\n---------------------------------------------------------------\n\n" ;

int main()
{
	DiamondTrap	Diamond("Rufus");

	Diamond.attack("Pirates");
	Diamond.attack("Kings");
	Diamond.attack("Lions");
	Diamond.beRepaired(10);
	Diamond.takeDamage(100);
	Diamond.guardGate();
	Diamond.highFivesGuys();
	Diamond.whoAmI();
}