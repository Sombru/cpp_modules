#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"


// virtual keyword means that the function/class can be overwritten or redeclared/redefined
// 
int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;

	Cat a;
	a.getBrain()->fillWithRandomIdeas();

	Cat b(a);

	std::cout << a.getBrain()->getIdea(4) << '\n';
}