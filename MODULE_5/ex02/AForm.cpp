#include "./includes/AForm.hpp"
#include "./includes/Bureaucrat.hpp"
/*----------------------------CONSTRUCTOR/DESTRUCTOR----------------------------*/
AForm::AForm():name("Aform"),grade(2),exGrade(2),isSigned(0)
{
    if (grade > 150 || exGrade > 150)
        throw AForm::GradeTooHighException();
    else if (grade < 1 || exGrade < 1)
        throw AForm::GradeTooLowException();
};
AForm::AForm(const std::string& name, const int grade, const int exGrade):name(name),grade(grade),exGrade(exGrade),isSigned(0)
{
    if (grade > 150 || exGrade > 150)
        throw AForm::GradeTooHighException();
    else if (grade < 1 || exGrade < 1)
        throw AForm::GradeTooLowException();
};
AForm::AForm(const AForm& rhs):name(rhs.name),grade(rhs.grade),exGrade(rhs.exGrade)
{
    if (grade > 150 || exGrade > 150)
        throw AForm::GradeTooHighException();
    else if (grade < 1 || exGrade < 1)
        throw AForm::GradeTooLowException();
};
AForm& AForm::operator=(const AForm& rhs)
{
    if (this == &rhs)
        return (*this);
    isSigned = rhs.isSigned;
    return (*this);
};
AForm::~AForm(){;};
/*----------------------------CONSTRUCTOR/DESTRUCTOR----------------------------*/

/*----------------------------MEMBER FUNCTION----------------------------*/
const char* AForm::GradeTooHighException::what(void) const throw()
{
    return "AForm's Grade greatest value shall be 150\n";
};

const char* AForm::GradeTooLowException::what(void) const throw()
{
    return "AForm's Grade lowest value shall be 1\n";
};

const char* AForm::FormNotSigned::what(void) const throw()
{
    return "AForm is not signed, please sign it before trying to execute it\n";
};

const char* AForm::GradeTooLow::what(void) const throw()
{
    return "That Bureaucrat has a too low grade, stop joking around...\n";
};
const std::string& AForm::getName(void) const {return name;};
int AForm::getGrade(void) const {return grade;};
int AForm::getExgrade(void) const {return exGrade;};
bool AForm::getIsSigned(void) const {return isSigned;};

void AForm::setIsSigned(bool value) {isSigned = value;}

void AForm::beSigned(const Bureaucrat& rhs)
{
    if (rhs.getGrade() > getGrade())
        throw AForm::GradeTooLowException();
    setIsSigned(true);
};

void AForm::execute(Bureaucrat const & executor) const
{
    if (!isSigned)
        AForm::FormNotSigned();
    if (executor.getGrade() > exGrade)
        AForm::GradeTooLow();
    formMessage();
}
/*----------------------------MEMBER FUNCTION----------------------------*/
