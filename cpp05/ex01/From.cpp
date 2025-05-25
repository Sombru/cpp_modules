#include "Form.hpp"
#include <iostream>

Form::Form(t_attributes attributes)
: mName(attributes.Name),
  mSigned(attributes.Signed),
  mGradeToSign(attributes.GradeToSign),
  mGradeToExecute(attributes.GradeToExecute)
{
	if (mGradeToSign < GRADE_MAX || mGradeToExecute < GRADE_MAX)
		throw GradeTooHighException();
	if (mGradeToSign > GRADE_MIN || mGradeToExecute > GRADE_MIN)
		throw GradeTooLowException();
	std::cout << "Form constructor: " << mName << '\n';
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

const int Form::getGradeToSign() const
{
	return this->mGradeToSign;
}

const int Form::getGradeToExecute() const
{
	return this->mGradeToExecute;
}

bool Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > mGradeToSign)
	{
		throw GradeTooLowException();
		return EXIT_FAILURE;
	}
	mSigned = true;
	return EXIT_SUCCESS;
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Form: " << form.getName() << " signed: " << form.getSign()
		<< ", grade to sign: " << form.getGradeToSign()
		<< ", grade to execute: " << form.getGradeToExecute() << "]";
	return out;
}
