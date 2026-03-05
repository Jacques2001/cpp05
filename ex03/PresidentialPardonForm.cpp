#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : 
AForm("PresidentialPardonForm", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) :
AForm("PresidentialPardonForm", 25, 5)
{
    (void)other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    (void)other;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

int PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    try
    {
        if (this->getStatus() == 0)
            throw(AForm::NotSignedException());
        if (executor.getGrade() > this->getGradeExecute())
            throw(AForm::GradeTooLowException());
        std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
        return 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
}