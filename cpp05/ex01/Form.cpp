#include "Form.hpp"
#include <iostream>

Form::Form(t_attributes attributes)
: mName(attributes.Name),
  mSigned(attributes.Signed),
  mGradeToSign(attributes.GradeToSign),
  mGradeToExecute(attributes.GradeToExecute)
{
	try
	{
		if (mGradeToSign < GRADE_MAX || mGradeToExecute < GRADE_MAX)
			throw GradeTooHighException();
		if (mGradeToSign > GRADE_MIN || mGradeToExecute > GRADE_MIN)
			throw GradeTooLowException();
		std::cout << "Form constructor: " << mName << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

Form::Form(const Form &copy)
: mName(copy.mName),
  mSigned(copy.mSigned),
  mGradeToSign(copy.mGradeToSign),
  mGradeToExecute(copy.mGradeToExecute)
{
	std::cout << "Form copy constructor: " << mName << '\n';
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		// mName, mGradeToSign, mGradeToExecute are const, can't assign
		this->mSigned = other.mSigned;
	}
	return *this;
}

Form::~Form()
{
	std::cout << "Form destructor: " << mName << '\n';
}

std::string Form::getName() const
{
	return this->mName;
}

bool Form::getSign() const
{
	return this->mSigned;
}

int Form::getGradeToSign() const
{
	return this->mGradeToSign;
}

int Form::getGradeToExecute() const
{
	return this->mGradeToExecute;
}

bool Form::beSigned(const Bureaucrat &bureaucrat)
{
	try
	{
		if (bureaucrat.getGrade() > mGradeToSign)
			throw GradeTooLowException();
		if (this->getSign() == true)
			throw FormAlreadySignedException();
		
		mSigned = true;
		std::cout << bureaucrat << " signed " << *this << '\n';

		return EXIT_SUCCESS;
	}
	catch (const std::exception &e)
	{
		std::cout << bureaucrat << " couldn't sign " << *this << " because " << e.what() << '\n';
		return EXIT_FAILURE;
	}	
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "[Form: " << form.getName()
		<< " signed: " ;
		if (form.getSign() == true)
			std::cout << "YES";
		else
			std::cout << "NO";
		std::cout << ", grade to sign: " << form.getGradeToSign()
		<< ", grade to execute: " << form.getGradeToExecute() << "]";
	return out;
}
