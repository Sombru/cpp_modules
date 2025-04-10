#include "Zombie.hpp"

Zombie* newZombie(std::string);
void 	randomChump(std::string);

int main()
{
	Zombie bob("Bob");
	Zombie mike("Mike");
	Zombie john("");

	bob.announce();
	mike.announce();
	john.announce();

	Zombie* ptr = newZombie("Heaper");

	ptr->announce();

	delete ptr;

	randomChump("Chumper");
}
