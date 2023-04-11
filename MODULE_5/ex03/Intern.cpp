#include "./includes/Intern.hpp"
#include "./includes/AForm.hpp"
#include "./includes/PresidentialPardonForm.hpp"
#include "./includes/RobotomyRequestForm.hpp"
#include "./includes/ShrubberyCreationForm.hpp"

/*------------------------------CONSTRUCTOR/DESTRUCTOR------------------------------*/

Intern::Intern():_name("no"),_target("no"){initForm();};
Intern::Intern(const std::string& name, const std::string& target):_name(name),_target(target){initForm();};
Intern::Intern(const Intern& rhs){(void)rhs;};
Intern& Intern::operator=(const Intern& rhs)
{
    if (this == &rhs)
        return (*this);
    (void)rhs;
    initForm();
    return (*this);
};
Intern::~Intern(){};
/*------------------------------CONSTRUCTOR/DESTRUCTOR------------------------------*/

/*------------------------------MAKEFORM------------------------------*/
AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
    int i = -1;
    while (++i < 3)
    {
        if (name == _form[i]._name)
        {
            std::cout << "Intern creates " << _form[i]._name << std::endl;
            return (_form[i].make(target));
        }
    }
    std::cerr << "YOUR SLAVE I MEAN INTERNEE CANT CREATE A FORM THAT DOES NOT EXIST\n";
    return NULL;
}

void Intern::initForm(void)
{
    _form[0]._name = "presidential pardon";
    _form[0].make = createPresidentialForm;
    _form[1]._name = "robotomy request";
    _form[1].make = createRobotomyForm;
    _form[2]._name = "shrubbery creation";
    _form[2].make = createShrubberyForm;
}
AForm* Intern::createRobotomyForm(const std::string& target) {return new RobotomyRequestForm(target);};
AForm* Intern::createShrubberyForm(const std::string& target) {return new ShrubberyCreationForm(target);};
AForm* Intern::createPresidentialForm(const std::string& target) {return new PresidentialPardonForm(target);};

/*------------------------------MAKEFORM------------------------------*/
