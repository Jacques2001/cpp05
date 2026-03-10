#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() 
{
    AForm *trivial = new ShrubberyCreationForm("home");
    AForm *useful = new RobotomyRequestForm("z");
    AForm *important = new PresidentialPardonForm("I");
    Bureaucrat x("Jacques", 5);
    Bureaucrat z("Nobody", 150);
    Bureaucrat y("Signer", 20);
    
    z.signAForm(useful);
    z.signAForm(trivial);
    x.signAForm(important);
    y.signAForm(trivial);
    y.signAForm(important);
    x.executeForm(*trivial);
    x.executeForm(*useful);
    x.executeForm(*important);
    delete trivial;
    delete useful;
    delete important;
    return 0;
}