#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"
class Bureaucrat; // I love linking problems 

typedef struct s_attributes
{
	std::string Name;
	bool Signed;
	int GradeToSign;
	int GradeToExecute;
}			t_attributes;


class Form
{
private:
	const std::string mName;
	bool mSigned;
	const int mGradeToSign;
	const int mGradeToExecute;

public:
	Form(t_attributes atributes);
	Form(const Form &copy);
	Form &operator=(const Form &other);
	~Form();

	std::string getName() const;
	bool getSign() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	bool beSigned(const Bureaucrat &bureaucrat);

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

	class FormAlreadySignedException 
	: public std::exception
	{
	public:
		const char *what() const throw()
		{
			return "Form already signed!";
		}
	};
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif