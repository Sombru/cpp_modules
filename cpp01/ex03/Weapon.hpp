#pragma once
#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string.h>
#include <iomanip>

class Weapon
{
private:
	std::string type;	

public:
	Weapon(std::string const type);
	~Weapon();

	void setType(std::string const to_set);
	
	std::string const &getType();
};

#endif