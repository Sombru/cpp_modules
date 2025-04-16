#include "ClapTrap.hpp"

int main()
{
	// Create ClapTrap objects
	ClapTrap Bob("Bob");
	ClapTrap Dave("Dave");

	// Clone a ClapTrap
	ClapTrap DaveClone(Dave);

	// Test attack
	Bob.attack("Dave");
	Dave.takeDamage(3);

	// Test repair
	Dave.beRepaired(5);

	// Test cloning behavior
	DaveClone.attack("Bob");
	Bob.takeDamage(2);

	// Test assignment operator
	ClapTrap Alice("Alice");
	Alice = Bob;
	Alice.attack("DaveClone");

	Bob.takeDamage(15); 
	Bob.beRepaired(10);

	return 0;
}