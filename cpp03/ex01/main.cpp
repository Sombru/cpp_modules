#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#define GURADS std::cout << "\n---------------------------------------------------------------\n\n" ;

int main()
{
	ScavTrap scav1("Scavvy");
	ScavTrap scav2("Guardian");

	GURADS
	scav1.attack("an enemy");
	scav2.takeDamage(30);
	scav2.beRepaired(20);
	scav1.guardGate();

	GURADS

    ScavTrap scav3(scav1);

    scav2 = scav1;

    return 0;
}