#ifndef __BUREAUCRAT_HPP_
#define __BUREAUCRAT_HPP_
#include <string>
#include <iostream>

class Bureaucrat
{
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat& rhs);
        Bureaucrat& operator=(const Bureaucrat& rhs);
        Bureaucrat(const std::string& name, int grade);
        ~Bureaucrat();
        const std::string& getName(void) const;
        int getGrade(void) const;

        void upGrade(void);
        void downGrade(void);
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

    private:
        const std::string name;
        int grade;
};
# endif
