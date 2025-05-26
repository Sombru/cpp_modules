#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource constructor\n";
	for (int i = 0; i < MATERIA_SIZE; i++)
	{
		learnedMaterias[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	std::cout << "MateriaSource copy constructor\n";
	for (int i = 0; i < MATERIA_SIZE; i++)
	{
		if (copy.learnedMaterias[i])
			learnedMaterias[i] = copy.learnedMaterias[i]->clone();
		else
			learnedMaterias[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		std::cout << "MateriaSource assignment operator\n";
		for (int i = 0; i < MATERIA_SIZE; i++)
		{
			delete learnedMaterias[i];
			if (other.learnedMaterias[i])
				learnedMaterias[i] = other.learnedMaterias[i]->clone();
			else
				learnedMaterias[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor\n";
	for (int i = 0; i < MATERIA_SIZE; i++)
	{
		delete learnedMaterias[i];
	}
}

void MateriaSource::learnMateria(AMateria *materia)
{
	if (!materia)
	{
		std::cout << "Cannot learn a NULL materia\n";
		return;
	}

	for (int i = 0; i < MATERIA_SIZE; i++)
	{
		if (!learnedMaterias[i])
		{
			learnedMaterias[i] = materia;
			std::cout << "Learned materia of type " << materia->getType() << " in slot " << i << '\n';
			return;
		}
	}
	std::cout << "MateriaSource is full, cannot learn more materias\n";
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < MATERIA_SIZE; i++)
	{
		if (learnedMaterias[i] && learnedMaterias[i]->getType() == type)
		{
			std::cout << "Creating materia of type " << type << '\n';
			return learnedMaterias[i]->clone();
		}
	}
	std::cout << "No materia of type " << type << " found\n";
	return NULL;
}