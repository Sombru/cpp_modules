#pragma once
#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string.h>
#include <iomanip>
#include "Weapon.hpp"

class HumanA
{
private:
	std::string _name;
	Weapon &_weapon; // reference to weapon to not make copy of an object

public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();

	void attack();
};

#endif