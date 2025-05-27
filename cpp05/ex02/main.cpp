#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	Bureaucrat alice(1, "Alice");	   // Highest grade
	Bureaucrat bob(140, "Bob");		   // Low grade
	Bureaucrat charlie(50, "Charlie"); // Medium grade

	PresidentialPardonForm pardon("Arthur Dent");
	ShrubberyCreationForm shrub("garden");
	RobotomyRequestForm robo("Marvin");

	std::cout << "\n--- Signing Forms ---\n";
	alice.signAForm(pardon); // Should succeed
	bob.signAForm(shrub);	 // Should succeed
	charlie.signAForm(robo); // Should succeed

	// Try to sign again (should fail: already signed)
	alice.signAForm(pardon);

	// Try to sign with too low grade
	bob.signAForm(pardon);

	std::cout << "\n--- Executing Forms ---\n";
	alice.executeForm(pardon); // Should succeed
	bob.executeForm(shrub);
	charlie.executeForm(robo);

	bob.executeForm(pardon);

	ShrubberyCreationForm shrub2("backyard");
	bob.executeForm(shrub2);

	alice.executeForm(shrub);
	alice.executeForm(robo);
	// srand(time(0));

	// std::cout << (std::rand()) << '\n';
	std::cout << "\n--- End of tests ---\n";
	return 0;
}