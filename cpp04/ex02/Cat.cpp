#include "Cat.hpp"

Cat::Cat()
: Animal("cat"), brain(new Brain)
{
	std::cout << "Cat default constructor\n";
}

Cat::Cat(const Cat &copy)
: Animal(copy.getType()), brain(new Brain)
{
	if (copy.brain->has_ideas == true)
	{
		for (int i = 0; i < 100; i++)
			brain->setIdea(copy.brain->getIdea(i), i);
	}
	std::cout << "Cat copy constructor\n";
}

Cat &Cat::operator=(const Cat &copy)
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

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor\n";
}

Brain* Cat::getBrain()
{
	return this->brain;
}

void Cat::makeSound() const
{
	std::cout << "I am a cat *mew mew*\n";
}