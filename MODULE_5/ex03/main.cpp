#include "./includes/Bureaucrat.hpp"
#include "./includes/AForm.hpp"
#include "./includes/PresidentialPardonForm.hpp"
#include "./includes/RobotomyRequestForm.hpp"
#include "./includes/ShrubberyCreationForm.hpp"
#include "./includes/Intern.hpp"
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    std::cout << bureaucrat.getName() << " bureaucrat grade is "
              << bureaucrat.getGrade() << std::endl;
    return os;
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    std::cout << form.getName() << " Form grade is "
              << form.getGrade() << " Exec grade is : "
              << form.getExgrade() << " isSigned value: "
              << form.getIsSigned() << std::endl;
    return os;
}

int	main()
{
    AForm	*f1;
    AForm	*f2;
    AForm	*f3;
    try
    {
        Bureaucrat	thiery = Bureaucrat("Thiery", 3);
        Bureaucrat	thiery_copy = thiery;
        Bureaucrat	sophie = Bureaucrat("Sophie", 150);
        Bureaucrat	lou = Bureaucrat("Lou", 20);

        Intern		claireDespagneSlave = Intern();

        f1 = claireDespagneSlave.makeForm("shrubbery creation", "campus");
        f2 = claireDespagneSlave.makeForm("robotomy request", "a rat");
        f3 = claireDespagneSlave.makeForm("presidential pardon", "Captain Sparrow");
        claireDespagneSlave.makeForm("censor", "Claire Despagne");

        if (f1)
        {
            thiery.executeForm(*f1);
            sophie.signForm(*f1);
            thiery.signForm(*f1);
            sophie.executeForm(*f1);
            thiery.executeForm(*f1);
        }
        if (f2)
        {
            lou.signForm(*f2);
            lou.executeForm(*f2);
        }
        if (f3)
        {
            lou.signForm(*f3);
            lou.executeForm(*f3);
            thiery.executeForm(*f3);
        }
        delete f1;
	    delete f2;
	    delete f3;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        delete f1;
	    delete f2;
	    delete f3;
    }
	return 0;
}
