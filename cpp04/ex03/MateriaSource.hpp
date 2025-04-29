#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

#define MATERIA_SIZE 4

class MateriaSource
: public IMateriaSource
{
private:
	AMateria *learnedMAterias[MATERIA_SIZE];

public:
	MateriaSource(/* args */);
	MateriaSource(const MateriaSource &copy);
	MateriaSource &operator=(const MateriaSource &other);

	~MateriaSource();

	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const &type);
};

#endif