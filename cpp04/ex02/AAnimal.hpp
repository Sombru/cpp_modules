#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

// abstract class has atleast 1 virtual function
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
	virtual void makeSound() const = 0; // pure virtual function

};

#endif