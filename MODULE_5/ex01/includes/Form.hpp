#ifndef __FORM_HPP_
#define __FORM_HPP_
#include <string>
#include <iostream>
class Bureaucrat;
class Form
{
    public:
        Form();
        Form(const std::string& name, const int grade, const int exGrade);
        Form(const Form& rhs);
        Form& operator=(const Form& rhs);
        ~Form();

        class GradeTooHighException: public std::exception
        {
            public:
                virtual const char* what(void) const throw();
        };
        class GradeTooLowException: public std::exception
        {
            public:
                virtual const char* what(void) const throw();
        };

        const std::string& getName() const;
        int  getGrade(void) const;
        int  getExgrade(void) const;
        bool getIsSigned(void) const;
        void beSigned(const Bureaucrat& rhs);
    private:
        const std::string name;
        const int grade;
        const int exGrade;
        bool isSigned;
};
#endif