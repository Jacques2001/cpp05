#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

Bureaucrat::Bureaucrat() : _name(""), _grade(0)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    try 
    {
        if (grade < 1)
            throw(Bureaucrat::GradeTooHighException());
        if (grade > 150)
            throw(Bureaucrat::GradeTooLowException());
        _grade = grade;
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

std::string Bureaucrat::getName()
{
    return _name;
}

int Bureaucrat::getGrade()
{
    return _grade;
}

void Bureaucrat::plusGrade()
{
    try
    {
        if (_grade - 1 < 1)
            throw (GradeTooHighException());
        _grade--;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void Bureaucrat::minGrade()
{
    try
    {
        if (_grade + 1 > 150)
            throw (GradeTooLowException());
        _grade++;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &info)
{
    out << info.getName() << ", bureaucrat grade " << info.getGrade();
    return (out);
}