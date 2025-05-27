#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Intern
{
private:
	
public:
	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern();

	AForm *makeForm(std::string formType, std::string fromTarget);
	AForm *makePresidetialForm(const std::string &target);
	AForm *makeRobotForm(const std::string &target);
	AForm *makeShruberForm(const std::string &target);

};

#endif