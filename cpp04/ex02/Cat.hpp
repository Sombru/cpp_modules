#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat
: public virtual Animal
{
private:	
	Brain* brain;

public:
	Cat();
	Cat(const Cat &copy);
	Cat &operator=(const Cat & copy);
	~Cat();

	Brain* getBrain();
	void makeSound() const;
};


#endif