#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main()
{
	int N = 5;

	Zombie* horde = zombieHorde(N, "Dave");

	for (int i = 0;N > i; i++)
	{
		horde[i].announce();
	}

	delete[] horde;
}