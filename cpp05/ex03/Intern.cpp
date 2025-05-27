#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern() {}
Intern::Intern(const Intern &) {}
Intern &Intern::operator=(const Intern &) { return *this; }
Intern::~Intern() {}

AForm *Intern::makeForm(std::string formType, std::string formTarget)
{
	std::string names[3] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"}; 

	AForm *(Intern::*creators[3])(const std::string &target) = {
		&Intern::makePresidetialForm,
		&Intern::makeRobotForm,
		&Intern::makeShruberForm
	};

	for (int i = 0; i < 3; ++i)
	{
		if (formType == names[i])
		{
			std::cout << "Intern creates " << formType << '\n';
			return (this->*creators[i])(formTarget);
		}
	}
	std::cout << "Intern: Unknown form type \"" << formType << "\"!" << '\n';
	return NULL;
}
AForm *Intern::makePresidetialForm(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeRobotForm(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::makeShruberForm(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}