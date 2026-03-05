#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() 
{
    Intern someRandomIntern;
    Bureaucrat z("Jacques", 1);
    AForm* rrf;
    AForm* nothing;
    nothing = someRandomIntern.makeForm("Do nothing", "Hmm");
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    z.signAForm(nothing);
    z.signAForm(rrf);
    z.executeForm(*rrf);
    if (nothing)
        z.executeForm(*nothing);
    delete rrf;
    return 0;
}