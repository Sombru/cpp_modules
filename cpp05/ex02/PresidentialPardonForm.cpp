#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm({"PresidentialPardonForm", false, PresidentialPardonGradeToSign, PresidentialPardonGradeToExec}),
  mTarget(target)
{
    
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
: AForm(other), mTarget(other.mTarget)
{

}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        mTarget = other.mTarget;
    }
    return *this;
}

void PresidentialPardonForm::executor() const
{
    std::cout << mTarget << " has been pardoned by Zaphod Beeblebrox" << '\n';
}