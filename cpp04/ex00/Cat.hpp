#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat
	: public virtual Animal
{
private:
public:
	Cat();
	Cat(const Cat &copy);
	Cat &operator=(const Cat &copy);
	~Cat();

	void makeSound() const;
};

#endif