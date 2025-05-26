#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

// PresidentialPardonForm: Required grades: sign 25, exec 5
// Informs that <target> has been pardoned by Zaphod Beeblebrox

#include "AForm.hpp"

#define PresidentialPardonGradeToSign 25
#define PresidentialPardonGradeToExec 5

class PresidentialPardonForm
: public AForm
{
private:
	std::string mTarget;
public:
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

	void executor() const;
};


"PresidentialPardonForm", false, PresidentialPardonGradeToSign, PresidentialPardonGradeToExec

#endif