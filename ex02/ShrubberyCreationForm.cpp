#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
AForm("ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
AForm("ShrubberyCreationForm", 145, 137)
{
    (void)other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    (void)other;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

int ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    std::string filename(_target + "_shrubbery");
    try 
    {
        if (this->getStatus() == 0)
            throw(AForm::NotSignedException());
        if (executor.getGrade() > this->getGradeExecute())
            throw(AForm::GradeTooLowException());
        std::ofstream file(filename.c_str());
        file << "test" << std::endl;
        return 0;
        // a completer
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}