#include "./includes/RobotomyRequestForm.hpp"
#include "./includes/AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():AForm("test", 72, 45),target("target")
{
    int grade = this -> getGrade();
    int exGrade = this -> getExgrade();
    if (grade > 150 || exGrade > 150)
        throw AForm::GradeTooHighException();
    else if (grade < 1 || exGrade < 1)
        throw AForm::GradeTooLowException();
}
RobotomyRequestForm::RobotomyRequestForm(const std::string& target):AForm(target, 72, 45),target(target)
{
    int grade = this -> getGrade();
    int exGrade = this -> getExgrade();
    if (grade > 150 || exGrade > 150)
        throw AForm::GradeTooHighException();
    else if (grade < 1 || exGrade < 1)
        throw AForm::GradeTooLowException();
};
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs):AForm(rhs.getTarget(), 72, 45),target(rhs.target)
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
        std::cout << this -> getName() << " has been robotomized\n";
    else
        std::cout << "Robotomization of " << this -> getName() << " failled\n";  
    robotomized = robotomized == true ? false : true;
}
RobotomyRequestForm::~RobotomyRequestForm(){;};
/*----------------------------CONSTRUCTOR/DESTRUCTOR----------------------------*/
/*----------------------------CONSTRUCTOR/DESTRUCTOR----------------------------*/
const std::string& RobotomyRequestForm::getTarget(void) const {return target;};
/*----------------------------CONSTRUCTOR/DESTRUCTOR----------------------------*/