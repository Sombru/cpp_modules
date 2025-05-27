#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	// form attributes
	t_attributes attr1 = {"FormA", false, 54, 30};
	t_attributes attr2 = {"FormB", false, 1, 1};
	t_attributes attr3 = {"FormC", false, 150, 150};

	Form formA(attr1);
	Form formB(attr2);
	Form formC(attr3);

	Bureaucrat bob(75, "Bob");
	Bureaucrat alice(1, "Alice");
	Bureaucrat tom(150, "Tom");

	std::cout << "\n--- Bureaucrats ---\n";
	std::cout << bob << '\n';
	std::cout << alice << '\n';
	std::cout << tom << '\n';

	std::cout << "\n--- Forms ---\n";
	std::cout << formA << '\n';
	std::cout << formB << '\n';
	std::cout << formC << '\n';

	std::cout << "\n--- Signing attempts ---\n";
	bob.signForm(formA);   // Should fail (grade too low)
	tom.signForm(formA);   // Should fail (grade too low)
	alice.signForm(formB); // Should succeed
	tom.signForm(formB);   // Should fail (grade too low)
	bob.signForm(formC);   // Should fail (grade too low)
	tom.signForm(formC);   // Should succeed

	return 0;
}

// Norm for exceptions in C++ OOP projects like this:

// Handle the exception locally (e.g., print an error message, log the failure, etc.).
// Allow the program to continue running so other operations;
// Only terminate if the exception is truly unrecoverable 
// and makes further execution unsafe or meaningless (e.g., failed to allocate critical resources, corrupted state)