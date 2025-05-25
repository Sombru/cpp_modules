#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP

#include <string>
#include <iostream>
#include <stdexcept> // For std::exception
#include "Form.hpp"

#define GRADE_MIN 150
#define GRADE_MAX 1


class Bureaucrat
{
private:
	const std::string mName;
	int mGrade;

public:
	Bureaucrat(int grade, const std::string name);
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();

	std::string getName() const;
	int getGrade() const;

	void setGrade(int grade);

	void signForm(Form &form);

	class GradeTooHighException 
	: public std::exception // inherit exception class
	{
	public:
		const char *what() const throw()
		{
			return "Grade is too high!";
		}
	};

	class GradeTooLowException 
	: public std::exception
	{
	public:
		const char *what() const throw()
		{
			return "Grade is too low!";
		}
	};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif