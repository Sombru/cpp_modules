#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include <iostream>

class AMateria
{
protected:
	/* data */

public:
	AMateria(std::string const &type);

	std::string const & getType() const; //Returns the materia type

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
	~AMateria();
};

#endif