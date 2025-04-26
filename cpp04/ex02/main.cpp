#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"


// virtual keyword means that the function/class can be overwritten or redeclared/redefined
// 
int main()
{
	Dog dogy;

	dogy.makeSound();

	Cat a;
	a.getBrain()->fillWithRandomIdeas();

	a.getBrain()->setIdea("skibidi toilet", 4);
	Cat b(a);

	std::cout << a.getBrain()->getIdea(4) << '\n';

}
