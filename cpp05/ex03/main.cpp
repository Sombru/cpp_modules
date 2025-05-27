#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	Bureaucrat alice(1, "alice");
	Intern someIntern;
	AForm *f1 = someIntern.makeForm("robotomy request", "Bender");
	AForm *f2 = someIntern.makeForm("shrubbery creation", "garden");
	AForm *f3 = someIntern.makeForm("presidential pardon", "Arthur Dent");
	AForm *f4 = someIntern.makeForm("unknown form", "nobody");

	f1->execute(alice);
	f1->beSigned(alice);
	f1->execute(alice);
	delete f1;
	delete f2;
	delete f3;
	delete f4;

	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");

	rrf->beSigned(alice);
	rrf->execute(alice);
	delete rrf;
}