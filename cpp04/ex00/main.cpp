#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"


// virtual keyword means that the function/class can be overwritten or redeclared/redefin
// 
int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	// j->Animal::makeSound(); will output animal sounds
	meta->makeSound();
	
	delete meta;
	delete j;
	delete i;
	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();
		std::cout << i->getType() << " " << std::endl;
		i->WrongAnimal::makeSound(); //will output the WrongAnimal sound!
		meta->makeSound();
	}
}