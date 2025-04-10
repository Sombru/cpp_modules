#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string.h>
#include <iomanip>

class Zombie
{
private:
	std::string name;

public:
	Zombie();
	Zombie(std::string name);
	~Zombie();

	//getters
	std::string _getNanme( void );
	
	//setters
	void _setName(std::string name);

	// other
	void announce( void );

};

#endif
