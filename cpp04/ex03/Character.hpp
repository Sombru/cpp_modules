#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#define SIZE 4

class Character
: public ICharacter
{
private:
	std::string mName;	
	AMateria *mInventory[SIZE];	

public:
	Character(std::string name);
	Character(const Character &copy);
	Character &operator=(const Character &other);
	~Character();

	bool has_inventory;
	std::string const &getName() const;
	void equip(AMateria *materia);
	void unequip(int idx);
	void use(int idx, ICharacter &target);

};


#endif