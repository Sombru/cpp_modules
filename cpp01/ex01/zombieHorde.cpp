#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
	{
		return 0;
	}

	Zombie* zombie_ptr = new Zombie[N];

	for (int i = 0; N > i; i++)
	{
		// if we compile with c++11 we could ahve used to_string method to easly count the zombies
		// zombie_ptr[i]._setName(name + "_" + std::to_string(i + 1))
		zombie_ptr[i]._setName(name);
	}
	
	return (zombie_ptr);
}