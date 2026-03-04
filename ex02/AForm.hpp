#ifndef AAForm_HPP
#define AAForm_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class AForm
{
    private :
        const std::string _name;
        bool _signed;
        const int _gradeSign;
        const int _gradeExecute;
    public :
        AForm();
        AForm(std::string name, int grade_sign, int grade_execute);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();
        int getGradeSign() const;
        int getGradeExecute() const;
        std::string getAFormName() const;
        int beSigned(Bureaucrat& employee);
        bool getStatus() const;
        virtual int execute(Bureaucrat const &executor) const = 0;
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
        class NotSignedException : public std::exception
        {
            public :
                virtual const char* what() const throw();
        };

};

std::ostream &operator<<(std::ostream &out, AForm &info);


#endif