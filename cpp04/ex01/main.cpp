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

	a.getBrain()->setIdea("skibidi toilet", 4);
	Cat b(a);

	std::cout << a.getBrain()->getIdea(4) << '\n';

	// std::cout << "==== Aniaml Brain's tests ====\n";

	// Animal* Animals[50];
	// for (int i = 0; i < 25; i++)
	//   Animals[i] = new Cat();
	// for (int i = 25; i < 50; i++)
	//   Animals[i] = new Dog();
	// for (int i = 0; i < 50; i++)
	//   delete Animals[i];
}
