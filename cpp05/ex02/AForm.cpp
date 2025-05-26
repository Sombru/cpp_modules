#include "AForm.hpp"
#include <iostream>

AForm::AForm(t_attributes attributes)
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
		std::cout << "AForm constructor: " << mName << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

AForm::AForm(const AForm &copy)
: mName(copy.mName),
  mSigned(copy.mSigned),
  mGradeToSign(copy.mGradeToSign),
  mGradeToExecute(copy.mGradeToExecute)
{
	std::cout << "AForm copy constructor: " << mName << '\n';
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		// mName, mGradeToSign, mGradeToExecute are const, can't assign
		this->mSigned = other.mSigned;
	}
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm destructor: " << mName << '\n';
}

std::string AForm::getName() const
{
	return this->mName;
}

bool AForm::getSign() const
{
	return this->mSigned;
}

int AForm::getGradeToSign() const
{
	return this->mGradeToSign;
}

int AForm::getGradeToExecute() const
{
	return this->mGradeToExecute;
}

bool AForm::beSigned(const Bureaucrat &bureaucrat)
{
	try
	{
		if (bureaucrat.getGrade() > mGradeToSign)
			throw GradeTooLowException();
		if (this->getSign() == true)
			throw AFormAlreadySignedException();
		
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

std::ostream &operator<<(std::ostream &out, const AForm &AForm)
{
	out << "[AForm: " << AForm.getName()
		<< " signed: " ;
		if (AForm.getSign() == true)
			std::cout << "YES";
		else
			std::cout << "NO";
		std::cout << ", grade to sign: " << AForm.getGradeToSign()
		<< ", grade to execute: " << AForm.getGradeToExecute() << "]";
	return out;
}
