#include "AForm.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

Form::Form() : 
_name(""),
_signed(0),
_gradeSign(150),
_gradeExecute(150)
{
}

Form::Form(std::string name, int grade_sign, int grade_execute) :
_name(name), _signed(0),
_gradeSign(grade_sign), 
_gradeExecute(grade_execute)
{
    try
    {
        if (_gradeSign < 1 || _gradeExecute < 1)
            throw (Form::GradeTooHighException());
        if (_gradeSign > 150 || _gradeExecute > 150)
            throw (Form::GradeTooLowException());
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

Form::Form(const Form &other) :
_name(other._name),
_gradeSign(other._gradeSign),
_gradeExecute(other._gradeExecute)
{
}

Form &Form::operator=(const Form &other)
{
    (void)other;
    return (*this);
}

Form::~Form()
{
}

int Form::getGradeSign()
{
    return _gradeSign;
}

int Form::getGradeExecute()
{
    return _gradeExecute;
}

std::string Form::getFormName()
{
    return _name;
}

bool Form::getStatus()
{
    return _signed;
}

std::ostream &operator<<(std::ostream &out, Form &info)
{
    out << "Form : " << info.getFormName()
        << ", grade to sign : " << info.getGradeSign()
        << ", grade to execute : " << info.getGradeExecute();
    return (out);
}

int Form::beSigned(Bureaucrat &employee)
{
    try
    {
        if (employee.getGrade() > _gradeSign)
            throw (GradeTooLowException());
        if (_signed == 0)
            _signed = 1;
        return 1;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 0;
    }
}