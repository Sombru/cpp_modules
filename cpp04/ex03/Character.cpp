#include "Character.hpp"

Character::Character(std::string name)
: mName(name)
{
	std::cout << "Characer constructor\n";
}

Character::Character(const Character &copy)