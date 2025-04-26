#include "Dog.hpp"

Dog::Dog()
: Animal("Dog"), brain(new Brain)
{
	std::cout << "Dog default constructor\n";
}

Dog::Dog(const Dog &copy)
: Animal(copy.getType()), brain(new Brain)
{
	if (copy.brain->has_ideas == true)
	{
		for (int i = 0; i < 100; i++)
			brain->setIdea(copy.brain->getIdea(i), i);
	}
	std::cout << "Dog copy constructor\n";
}

Dog &Dog::operator=(const Dog &copy)
{
    if (this != &copy)
    {
        Animal::mType = copy.getType();
        delete brain;
        brain = new Brain();
        if (copy.brain->has_ideas == true)
        {
            for (int i = 0; i < 100; i++)
                brain->setIdea(copy.brain->getIdea(i), i);
        }
    }
    return *this;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor\n";
}

Brain* Dog::getBrain()
{
	return this->brain;
}

void Dog::makeSound() const
{
	std::cout << "I am a Dog *bark bark*\n";
}