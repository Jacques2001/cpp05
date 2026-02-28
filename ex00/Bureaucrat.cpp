#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(0)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    try 
    {
        if (grade < 1 || grade > 150)
            throw(std::exception("Out of range"));
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
        _grade = other._grade;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
}