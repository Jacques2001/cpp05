#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() 
{
    Bureaucrat boss("Boss", 1);
    Bureaucrat b("Jacques", 2);
    Bureaucrat c("Low", 2);
    Form a("Qualified", 3, 24);
    Form z("Whoever", 150, 70);
    Form x("Boss", 1, 1);
    b.signForm(a);
    c.signForm(a);
    b.signForm(z);
    boss.signForm(x);
    // std::cout << a << std::endl;
    return 0;
}