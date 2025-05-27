#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP

#include "AForm.hpp"
#include <string>

#define RobotomyRequestGradeToSign 72
#define RobotomyRequestGradeToExec 45

class RobotomyRequestForm : public AForm
{
private:
    std::string mTarget;
public:
    RobotomyRequestForm(std::string target);
    ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm &other);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

    void execute(Bureaucrat const &executor) const;
};
#endif