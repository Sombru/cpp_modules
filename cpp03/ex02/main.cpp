#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FlagTrap.hpp"

#define GURADS std::cout << "\n---------------------------------------------------------------\n\n" ;

int main()
{
	ScavTrap scav1("Scavvy");
	ScavTrap scav2("Guardian");
	FlagTrap flag1("Flaggy"); 

	GURADS
	flag1.attack("an enemy");
	scav2.takeDamage(30);
	scav2.beRepaired(20);
	scav1.guardGate();
	flag1.highFivesGuys();

	GURADS

    ScavTrap scav3(scav1);

    scav2 = scav1;

    return 0;
}