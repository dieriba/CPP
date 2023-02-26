#include "./includes/Form.hpp"
#include "./includes/Bureaucrat.hpp"
/*----------------------------CONSTRUCTOR/DESTRUCTOR----------------------------*/
Form::Form():name("form"),grade(2),exGrade(2),isSigned(0)
{
    if (grade > 150 || exGrade > 150)
        throw Form::GradeTooHighException();
    else if (grade < 1 || exGrade < 1)
        throw Form::GradeTooLowException();
};
Form::Form(const std::string& name, const int grade, const int exGrade):name(name),grade(grade),exGrade(exGrade)
{
    if (grade > 150 || exGrade > 150)
        throw Form::GradeTooHighException();
    else if (grade < 1 || exGrade < 1)
        throw Form::GradeTooLowException();
};
Form::Form(const Form& rhs):name(rhs.name),grade(rhs.grade),exGrade(rhs.exGrade)
{
    if (grade > 150 || exGrade > 150)
        throw Form::GradeTooHighException();
    else if (grade < 1 || exGrade < 1)
        throw Form::GradeTooLowException();
};
Form& Form::operator=(const Form& rhs)
{
    if (this == &rhs)
        return (*this);
    isSigned = rhs.isSigned;
    return (*this);
};
Form::~Form(){;};
/*----------------------------CONSTRUCTOR/DESTRUCTOR----------------------------*/

/*----------------------------MEMBER FUNCTION----------------------------*/
const char* Form::GradeTooHighException::what(void) const throw()
{
    return "Form's Grade greatest value shall be 1\n";
};

const char* Form::GradeTooLowException::what(void) const throw()
{
    return "Form's Grade greatest value shall be 1\n";
};
const std::string& Form::getName(void) const {return name;};
int Form::getGrade(void) const {return grade;};
int Form::getExgrade(void) const {return exGrade;};
bool Form::getIsSigned(void) const {return isSigned;};

void Form::beSigned(const Bureaucrat& rhs)
{
    if (rhs.getGrade() > grade)
        throw Form::GradeTooLowException();
    isSigned = 1;
};

/*----------------------------MEMBER FUNCTION----------------------------*/
