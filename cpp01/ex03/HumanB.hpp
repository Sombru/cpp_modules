#pragma once
#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string.h>
#include <iomanip>
#include "Weapon.hpp"

class HumanB
{
private:
	std::string _name;
	Weapon *_weapon; // pointer to weapon to not make copy of an object

public:
	HumanB(std::string name);
	~HumanB();

	void setWeapon(Weapon &weapon);
	void attack();

};

#endif