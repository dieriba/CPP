#ifndef __AFORM_HPP_
#define __AFORM_HPP_
#include <string>
#include <iostream>
class Bureaucrat;
class AForm
{
    public:
        AForm();
        AForm(const std::string& name, const int grade, const int exGrade);
        AForm(const AForm& rhs);
        AForm& operator=(const AForm& rhs);
        virtual ~AForm();

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
        class FormNotSigned: public std::exception
        {
            public:
                virtual const char* what(void) const throw();
        };
        class GradeTooLow: public std::exception
        {
            public:
                virtual const char* what(void) const throw();
        };
        const std::string& getName() const;
        int  getGrade(void) const;
        int  getExgrade(void) const;
        bool getIsSigned(void) const;
        virtual const std::string& getTarget(void) const = 0;
        virtual void formMessage(void) const = 0;
        void beSigned(const Bureaucrat& rhs);
        void execute(Bureaucrat const & executor) const;
        void setIsSigned(bool value);
    private:
        const std::string name;
        const int grade;
        const int exGrade;
        bool isSigned;
};
#endif