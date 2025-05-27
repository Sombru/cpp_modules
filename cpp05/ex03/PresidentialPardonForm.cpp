#include "PresidentialPardonForm.hpp"
#include <iostream>

t_attributes PresidentialPardonTemplate = {"PresidentialPardon", false, PresidentialPardonGradeToSign, PresidentialPardonGradeToExec};

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm(PresidentialPardonTemplate), mTarget(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
: AForm(other), mTarget(other.mTarget)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		mTarget = other.mTarget;
	}
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (this->getSign() == false)
			throw AFormNotSignedException();
		else if (executor.getGrade() > this->getGradeToExecute())
			throw GradeTooLowException();
		else
		{
			std::cout << executor << " executed " << *this << '\n';
			std::cout << mTarget << " has been pardoned by Zaphod Beeblebrox" << '\n';
		}
	}
	catch (const std::exception &e)
	{
		std::cout << executor << " couldn't sign " << *this << " because " << e.what() << '\n';
	}
}