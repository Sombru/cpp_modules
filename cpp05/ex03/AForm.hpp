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
	virtual ~AForm();

	std::string getName() const;
	bool getSign() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	bool beSigned(const Bureaucrat &bureaucrat);
	virtual void execute(Bureaucrat const & executor) const = 0;

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
			return "Form already signed!";
		}
	};

	class AFormNotSignedException 
	: public std::exception
	{
	public:
		const char *what() const throw()
		{
			return "Cant execute not signed Form";
		}
	};
};

std::ostream &operator<<(std::ostream &out, const AForm &AForm);

#endif