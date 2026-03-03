#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Form
{
    private :
        const std::string _name;
        bool _signed;
        const int _gradeSign;
        const int _gradeExecute;
    public :
        Form();
        Form(std::string name, int grade_sign, int grade_execute);
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();
        int getGradeSign();
        int getGradeExecute();
        std::string getFormName();
        int beSigned(Bureaucrat& employee);
        bool getStatus();
        class GradeTooHighException : public std::exception
        {
            public :
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public :
                virtual const char* what() const throw();
        };

};

std::ostream &operator<<(std::ostream &out, Form &info);


#endif