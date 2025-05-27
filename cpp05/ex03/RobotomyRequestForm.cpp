#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

t_attributes RobotomyRequestTemplate = {"RobotomyRequest", false, RobotomyRequestGradeToSign, RobotomyRequestGradeToExec};

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm(RobotomyRequestTemplate), mTarget(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
: AForm(other), mTarget(other.mTarget)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		mTarget = other.mTarget;
	}
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{

	try
	{
		if (this->getSign() == false)
			throw AFormNotSignedException();
		else if (executor.getGrade() > this->getGradeToExecute())
			throw GradeTooLowException();
		else
		{
			srand(time(0));
			std::cout << executor << " executed " << *this << '\n';
			std::cout << "* drilling noises *\n";
			if ((std::rand() % 2) == 0)
				std::cout << mTarget << " has been robotomized successfully!\n";
			else
				std::cout << "Robotomy failed on " << mTarget << "!\n";
		}
	}
	catch (const std::exception &e)
	{
		std::cout << executor << " couldn't sign " << *this << " because " << e.what() << '\n';
	}
}