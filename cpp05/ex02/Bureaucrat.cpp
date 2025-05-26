#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(int grade, const std::string name)
	: mName(name)
{
	try
	{
		if (grade < 1)
			throw GradeTooHighException(); // throw a function as a reuslt of exception
		if (grade > 150)
			throw GradeTooLowException();
		mGrade = grade;
	}
	// catch takes whatever throw returns
	catch (const std::exception &e) // catch error, this code will be executed upon catching
	{
		std::cout << "error: " << e.what() << '\n';
	}

	std::cout << "Bureaucrat constructor with grade ";
	std::cout << mGrade << " \n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
	: mName(copy.mName), mGrade(copy.mGrade)
{
	std::cout << "Bureaucrat copy constructor\n";
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	this->mGrade = other.getGrade();

	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor\n";
}

std::string Bureaucrat::getName() const
{
	return this->mName;
}

int Bureaucrat::getGrade() const
{
	return this->mGrade;
}

void Bureaucrat::setGrade(int grade)
{
	try
	{
		if (grade < GRADE_MAX)
			throw GradeTooHighException(); // throw a function as a reuslt of exception
		if (grade > GRADE_MIN)
			throw GradeTooLowException();
		mGrade = grade;
	}
	// catch takes whatever throw returns
	catch (const std::exception &e) // catch error, this code will be executed upon catching
	{
		std::cout << "error: " << e.what() << '\n';
	}
}

void Bureaucrat::signAForm(AForm &AForm)
{
	AForm.beSigned(*this);
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}