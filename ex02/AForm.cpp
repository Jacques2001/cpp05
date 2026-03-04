#include "AForm.hpp"

const char* AForm::NotSignedException::what() const throw()
{
    return ("Not signed");
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

AForm::AForm() : 
_name(""),
_signed(0),
_gradeSign(150),
_gradeExecute(150)
{
}

AForm::AForm(std::string name, int grade_sign, int grade_execute) :
_name(name), _signed(0),
_gradeSign(grade_sign), 
_gradeExecute(grade_execute)
{
    try
    {
        if (_gradeSign < 1 || _gradeExecute < 1)
            throw (AForm::GradeTooHighException());
        if (_gradeSign > 150 || _gradeExecute > 150)
            throw (AForm::GradeTooLowException());
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

AForm::AForm(const AForm &other) :
_name(other._name),
_gradeSign(other._gradeSign),
_gradeExecute(other._gradeExecute)
{
}

AForm &AForm::operator=(const AForm &other)
{
    (void)other;
    return (*this);
}

AForm::~AForm()
{
}

int AForm::getGradeSign() const
{
    return _gradeSign;
}

int AForm::getGradeExecute() const
{
    return _gradeExecute;
}

std::string AForm::getAFormName() const
{
    return _name;
}

bool AForm::getStatus() const
{
    return _signed;
}

std::ostream &operator<<(std::ostream &out, AForm &info)
{
    out << "AForm : " << info.getAFormName()
        << ", grade to sign : " << info.getGradeSign()
        << ", grade to execute : " << info.getGradeExecute();
    return (out);
}

int AForm::beSigned(Bureaucrat &employee)
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