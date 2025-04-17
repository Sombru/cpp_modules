#include "ClapTrap.hpp"

#define GURADS std::cout << "\n---------------------------------------------------------------\n\n" ;

int main()
{
	ClapTrap Bob("Bob");
	ClapTrap Dave("Dave");

	ClapTrap DaveClone(Dave);

	GURADS
	Bob.attack("Dave");
	Dave.takeDamage(3);

	Dave.check();

	Dave.beRepaired(5);

	Dave.check();

	DaveClone.attack("Bob");
	Bob.takeDamage(2);

	GURADS
	ClapTrap Alice("Alice");
	Alice = Bob;
	Alice.attack("DaveClone");


	Bob.takeDamage(15); 
	Bob.beRepaired(10);

	return 0;
}