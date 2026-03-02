#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Form
{
    private :
        const std::string _name;
        bool _signed;
        const int _gradeSign; // Grade required to sign the Form
        const int _gradeExecute; // Grade
    public :
        Form();
        Form(std::string name, int grade_sign, int grade_execute);
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();
        int getGradeSign();
        void beSigned(Bureaucrat &salaryman);
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