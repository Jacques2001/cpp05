#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() 
{
    AForm *trivial = new ShrubberyCreationForm("x");
    AForm *useful = new RobotomyRequestForm("z");
    AForm *important = new PresidentialPardonForm("I");
    Bureaucrat x("Jacques", 1);
    Bureaucrat z("Nobody", 72);
    
    z.signAForm(useful);
    z.signAForm(trivial);
    x.signAForm(important);
    x.executeForm(*trivial);
    x.executeForm(*useful);
    x.executeForm(*important);
    delete trivial;
    delete useful;
    delete important;
    return 0;
}