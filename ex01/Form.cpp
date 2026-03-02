#include "Form.hpp"

Form::Form() : 
_name(""),
_signed(0),
_gradeSign(0),
_gradeExecute(0)
{
}

Form::Form(std::string name, int grade_sign, int grade_execute) :
_name(name), _signed(0),
_gradeSign(grade_sign), 
_gradeExecute(grade_execute)
{
}

Form::Form(const Form &other) :
_name(other._name),
_gradeSign(other._gradeSign),
_gradeExecute(other._gradeExecute)
{
}

Form &Form::operator=(const Form &other)
{
    return (*this);
}

int Form::getGradeSign()
{
    return _gradeSign;
}