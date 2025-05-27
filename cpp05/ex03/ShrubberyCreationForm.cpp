#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

t_attributes ShrubberyCreationTemplate = {"ShrubberyCreation", false, ShrubberyCreationGradeToSign, ShrubberyCreationGradeToExec};


ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm(ShrubberyCreationTemplate), mTarget(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
: AForm(other), mTarget(other.mTarget)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		mTarget = other.mTarget;
	}
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
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
			std::ofstream file((mTarget + "_shrubbery").c_str());
			if (!file)
			{
				std::cerr << "Failed to create shrubbery file\n";
				return;
			}
			file << "       _-_\n"
					"    /~~   ~~\\\n"
					" /~~         ~~\\\n"
					"{               }\n"
					" \\  _-     -_  /\n"
					"   ~  \\\\ //  ~\n"
					"_- -   | | _- _\n"
					"  _ -  | |   -_\n"
					"      // \\\\\n";
			file.close();
			std::cout << "Shrubbery created in " << mTarget << "_shrubbery\n";
		}
	}
	catch (const std::exception &e)
	{
		std::cout << executor << " couldn't sign " << *this << " because " << e.what() << '\n';
	}
}