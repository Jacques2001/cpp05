#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() 
{
    Intern someRandomIntern;
    Bureaucrat z("Jacques", 1);
    AForm* rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    z.signAForm(rrf);
    z.executeForm(*rrf);
    return 0;
}