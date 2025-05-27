#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP

#include "AForm.hpp"
#include <string>

#define ShrubberyCreationGradeToSign 145
#define ShrubberyCreationGradeToExec 137

class ShrubberyCreationForm : public AForm
{
private:
    std::string mTarget;
public:
    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

    void execute(Bureaucrat const &executor) const;
};

#endif