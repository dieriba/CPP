#include "./includes/PresidentialPardonForm.hpp"
#include "./includes/AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("none", 25, 5),target("none")
{
    int grade = this -> getGrade();
    int exGrade = this -> getExgrade();
    if (grade > 150 || exGrade > 150)
        throw AForm::GradeTooHighException();
    else if (grade < 1 || exGrade < 1)
        throw AForm::GradeTooLowException();
}
PresidentialPardonForm::PresidentialPardonForm(const std::string& target):AForm("presidential pardon", 25, 5),target(target)
{
    int grade = this -> getGrade();
    int exGrade = this -> getExgrade();
    if (grade > 150 || exGrade > 150)
        throw AForm::GradeTooHighException();
    else if (grade < 1 || exGrade < 1)
        throw AForm::GradeTooLowException();
};
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs):AForm("presidential pardon", 25, 5),target(rhs.target)
{
    setIsSigned(rhs.getIsSigned());
};
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
    if (this == &rhs)
        return (*this);
    setIsSigned(rhs.getIsSigned());
    return (*this);
};
PresidentialPardonForm::~PresidentialPardonForm(){;};
/*----------------------------CONSTRUCTOR/DESTRUCTOR----------------------------*/

/*----------------------------MEMBER/FUNCTION----------------------------*/
void PresidentialPardonForm::formMessage(void) const
{
    std::cout << target << " has been pardonned by Zaphod Beeblebrox\n";
}
const std::string& PresidentialPardonForm::getTarget(void) const {return target;};
/*----------------------------MEMBER/FUNCTION----------------------------*/
