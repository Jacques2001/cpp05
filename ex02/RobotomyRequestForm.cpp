#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
AForm("RobotomyRequestForm", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
AForm("RobotomyRequestForm", 72, 45)
{
    (void)other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    (void)other;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

int RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    try
    {
        if (this->getStatus() == 0)
            throw(AForm::NotSignedException());
        if (executor.getGrade() > this->getGradeExecute())
            throw(AForm::GradeTooLowException());
        std::cout << "* BZZZZZZZ BZZZZZZZZ BZZZZZZZZZZ *" << std::endl;
        // creer proba
        return 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
}