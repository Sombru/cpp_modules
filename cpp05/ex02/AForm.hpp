#ifndef AForm_HPP
# define AForm_HPP

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


class AForm
{
private:
	const std::string mName;
	bool mSigned;
	const int mGradeToSign;
	const int mGradeToExecute;

public:
	AForm(t_attributes atributes);
	AForm(const AForm &copy);
	AForm &operator=(const AForm &other);
	virtual ~AForm() = 0;

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

	class AFormAlreadySignedException 
	: public std::exception
	{
	public:
		const char *what() const throw()
		{
			return "AForm already signed!";
		}
	};
};

std::ostream &operator<<(std::ostream &out, const AForm &AForm);

#endif