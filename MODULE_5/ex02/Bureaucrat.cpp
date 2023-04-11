#include "./includes/Bureaucrat.hpp"
#include "./includes/AForm.hpp"

/*------------------------------CONSTRUCTOR/DESTRUCTOR------------------------------*/
Bureaucrat::Bureaucrat():name("unknow"),grade(-1){};
Bureaucrat::Bureaucrat(const Bureaucrat& rhs):name(rhs.name),grade(rhs.grade){};
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
    if (this == &rhs)
        return (*this);
    grade = rhs.grade;
    return (*this);
};
Bureaucrat::~Bureaucrat(){};
Bureaucrat::Bureaucrat(const std::string& name, int grade):name(name)
{
    if (grade > 150)
        throw Bureaucrat::GradeTooHighException();
    if (grade < 1)
        throw Bureaucrat::GradeTooLowException();
    this -> grade = grade;
}
/*------------------------------CONSTRUCTOR/DESTRUCTOR------------------------------*/

/*------------------------------MEMBER FUNCTION GETTER------------------------------*/
const std::string& Bureaucrat::getName(void) const {return name;};
int Bureaucrat::getGrade(void) const {return grade;};
/*------------------------------MEMBER FUNCTION GETTER------------------------------*/

/*------------------------------MEMBER FUNCTION SETTER------------------------------*/
void Bureaucrat::upGrade(void)
{
    if (grade + 1 > 150)
        throw Bureaucrat::GradeTooHighException();
    grade++;
};

void Bureaucrat::downGrade(void)
{
    if (grade - 1 < 1)
        throw Bureaucrat::GradeTooLowException();
    grade--;
};

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return "Bureaucrate Grade's greatest value shall be 1\n";
};

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return "Bureaucrate Grade's greatest value shall be 1\n";
};

void Bureaucrat::signForm(AForm& form) const
{
    if (grade <= form.getGrade())
        std::cout << name << " signed form";
    else
        std::cout   << getName()
                    << " couldn't sign form because requirement were not met";
    form.setIsSigned(true);
    std::cout << std::endl;
};

void Bureaucrat::executeForm(AForm const & form)
{
    if (!form.getIsSigned() || grade > form.getExgrade())
    {
        std::cout   << name
                    << " do no meet the requirement to handle that form\n";
        return ;
    }
    form.execute(*this);
    std::cout << getName() << " executed " << form.getName() << std::endl;
}
/*------------------------------MEMBER FUNCTION SETTER------------------------------*/