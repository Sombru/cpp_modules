#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP 

#include <iostream>

class ClapTrap
{
protected: // is protected to give access to subclasses of this class
	const std::string _name; // probably const otherwise why = operator should change it?
	unsigned int _hp;
	unsigned int _mp;
	unsigned int _dmg;

public:
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &copy);
	ClapTrap &operator=(const ClapTrap &copy);
	~ClapTrap();

	std::string get_name() const;
	unsigned int get_hp() const;
	unsigned int get_mp() const;
	unsigned int get_dmg() const;

	void set_hp(unsigned int hp);
	void set_mp(unsigned int mp);
	void set_dmg(unsigned int dmg);

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void check();

};



#endif