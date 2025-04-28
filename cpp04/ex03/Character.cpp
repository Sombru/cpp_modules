#include "Character.hpp"

Character::Character(std::string name)
	: mName(name), has_inventory(false)
{
	for (int i = 0; i < SIZE; ++i)
		mInventory[i] = nullptr;
	std::cout << "Character constructor called for " << mName << '\n';
}

Character::Character(const Character &copy)
	: mName(copy.mName), has_inventory(copy.has_inventory)
{
	for (int i = 0; i < SIZE; ++i)
	{
		if (copy.mInventory[i])
			mInventory[i] = copy.mInventory[i]->clone(); // Deep copy
		else
			mInventory[i] = nullptr;
	}
	std::cout << "Character copy constructor called for " << mName << '\n';
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		mName = other.mName;
		has_inventory = other.has_inventory;

		for (int i = 0; i < SIZE; ++i)
		{
			delete mInventory[i];
			mInventory[i] = nullptr;
		}

		for (int i = 0; i < SIZE; ++i)
		{
			if (other.mInventory[i])
				mInventory[i] = other.mInventory[i]->clone();
		}
	}
	std::cout << "Character assignment operator called for " << mName << '\n';
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < SIZE; ++i)
		delete mInventory[i];
	std::cout << "Character destructor called for " << mName << '\n';
}

void Character::equip(AMateria *m)
{
	if (!m)
		return;

	for (int i = 0; i < SIZE; ++i)
	{
		if (!mInventory[i])
		{
			mInventory[i] = m;
			has_inventory = true;
			std::cout << "Equipped " << m->getType() << " in slot " << i << '\n';
			return;
		}
	}
	std::cout << "Inventory full, cannot equip " << m->getType() << '\n';
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= SIZE || !mInventory[idx])
	{
		std::cout << "Invalid unequip operation at index " << idx << '\n';
		return;
	}

	mInventory[idx] = nullptr;
	std::cout << "Unequipped slot " << idx << '\n';

	has_inventory = false;
	for (int i = 0; i < SIZE; ++i)
	{
		if (mInventory[i])
		{
			has_inventory = true;
			break;
		}
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= SIZE || !mInventory[idx])
	{
		std::cout << "Invalid use operation at index " << idx << '\n';
		return;
	}

	mInventory[idx]->use(target);
}