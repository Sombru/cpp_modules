#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	// // AForm attributes
	// t_attributes attr1 = {"AFormA", false, 54846, 30};
	// t_attributes attr2 = {"AFormB", false, 1, 1};
	// t_attributes attr3 = {"AFormC", false, 150, 150};

	// AForm AFormA(attr1);
	// AForm AFormB(attr2);
	// AForm AFormC(attr3);

	// Bureaucrat bob(75, "Bob");
	// Bureaucrat alice(1, "Alice");
	// Bureaucrat tom(150, "Tom");

	// std::cout << "\n--- Bureaucrats ---\n";
	// std::cout << bob << '\n';
	// std::cout << alice << '\n';
	// std::cout << tom << '\n';

	// std::cout << "\n--- AForms ---\n";
	// std::cout << AFormA << '\n';
	// std::cout << AFormB << '\n';
	// std::cout << AFormC << '\n';

	// std::cout << "\n--- Signing attempts ---\n";
	// bob.signAForm(AFormA);   // Should fail (grade too low)
	// tom.signAForm(AFormA);   // Should fail (grade too low)
	// alice.signAForm(AFormB); // Should succeed
	// tom.signAForm(AFormB);   // Should fail (grade too low)
	// bob.signAForm(AFormC);   // Should fail (grade too low)
	// tom.signAForm(AFormC);   // Should succeed

	PresidentialPardonForm P_Form("home");

	return 0;
}

// Norm for exceptions in C++ OOP projects like this:

// Handle the exception locally (e.g., print an error message, log the failure, etc.).
// Allow the program to continue running so other operations;
// Only terminate if the exception is truly unrecoverable 
// and makes further execution unsafe or meaningless (e.g., failed to allocate critical resources, corrupted state)