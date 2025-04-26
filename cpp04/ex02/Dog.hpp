#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog
: public virtual Animal
{
private:
	Brain* brain;

public:
	Dog();
	Dog(const Dog &copy);
	Dog &operator=(const Dog & copy);
	~Dog();

	Brain* getBrain();
	void makeSound() const;
};


#endif