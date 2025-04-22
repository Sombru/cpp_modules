#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
	std::string mType;

public:
	Animal();
	Animal(const std::string type); // constructor to set the type of an animal, subclasses will use it
	Animal(const Animal &copy);
	Animal &operator=(const Animal &copy);
	virtual ~Animal();

	std::string getType() const;
	virtual void makeSound() const;

};

#endif