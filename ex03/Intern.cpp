#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return (*this);
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(std::string name, std::string target)
{
    std::string Forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    for (int i = 0; i < 3; i++)
    {
        if (Forms[i] == name)
        {
            switch (i)
            {
                case 0 :
                {
                    std::cout << "Intern creates " << name << std::endl;
                    return new ShrubberyCreationForm(target);
                }
                case 1 :
                {
                    std::cout << "Intern creates " << name << std::endl;
                    return new RobotomyRequestForm(target);
                }
                case 2 :
                {
                    std::cout << "Intern creates " << name << std::endl;
                    return new PresidentialPardonForm(target);
                }
            }
        }
    }
    std::cout << name << " does not exist"<< std::endl;
    return NULL;
}