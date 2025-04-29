#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource constructor\n";
	for (int i = 0; i < MATERIA_SIZE; i++)
	{
		learnedMAterias[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	std::cout << "MateriaSource copy constructor\n";
	for (int i = 0; i < MATERIA_SIZE; i++)
	{
		if (copy.learnedMAterias[i])
			learnedMAterias[i] = copy.learnedMAterias[i]->clone();
		else
			learnedMAterias[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		std::cout << "MateriaSource assignment operator\n";
		for (int i = 0; i < MATERIA_SIZE; i++)
		{
			delete learnedMAterias[i];
			if (other.learnedMAterias[i])
				learnedMAterias[i] = other.learnedMAterias[i]->clone();
			else
				learnedMAterias[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor\n";
	for (int i = 0; i < MATERIA_SIZE; i++)
	{
		delete learnedMAterias[i];
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
		if (!learnedMAterias[i])
		{
			learnedMAterias[i] = materia;
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
		if (learnedMAterias[i] && learnedMAterias[i]->getType() == type)
		{
			std::cout << "Creating materia of type " << type << '\n';
			return learnedMAterias[i]->clone();
		}
	}
	std::cout << "No materia of type " << type << " found\n";
	return NULL;
}