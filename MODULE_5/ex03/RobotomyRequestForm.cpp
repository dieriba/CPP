#include "./includes/RobotomyRequestForm.hpp"
#include "./includes/AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():AForm("none", 72, 45),target("none")
{
    int grade = this -> getGrade();
    int exGrade = this -> getExgrade();
    if (grade > 150 || exGrade > 150)
        throw AForm::GradeTooHighException();
    else if (grade < 1 || exGrade < 1)
        throw AForm::GradeTooLowException();
}
RobotomyRequestForm::RobotomyRequestForm(const std::string& target):AForm("robotomy request", 72, 45),target(target)
{
    int grade = this -> getGrade();
    int exGrade = this -> getExgrade();
    if (grade > 150 || exGrade > 150)
        throw AForm::GradeTooHighException();
    else if (grade < 1 || exGrade < 1)
        throw AForm::GradeTooLowException();
};
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs):AForm("robotomy request", 72, 45),target(rhs.target)
{
    setIsSigned(rhs.getIsSigned());
};
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
    if (this == &rhs)
        return (*this);
    setIsSigned(rhs.getIsSigned());
    return (*this);
};
void RobotomyRequestForm::formMessage(void) const
{
    static bool robotomized = true;

    if (robotomized)
        std::cout << target << " has been robotomized\n";
    else
        std::cout << "Robotomization of " << this -> getName() << " failled\n";  
    robotomized = robotomized == true ? false : true;
}
RobotomyRequestForm::~RobotomyRequestForm(){;};
/*----------------------------CONSTRUCTOR/DESTRUCTOR----------------------------*/
/*----------------------------MEMBER/FUNCTION----------------------------*/
const std::string& RobotomyRequestForm::getTarget(void) const {return target;};
/*----------------------------MEMBER/FUNCTION----------------------------*/