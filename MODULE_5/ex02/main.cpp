#include "./includes/Bureaucrat.hpp"
#include "./includes/AForm.hpp"
#include "./includes/PresidentialPardonForm.hpp"
#include "./includes/RobotomyRequestForm.hpp"
#include "./includes/ShrubberyCreationForm.hpp"

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
	try
	{
		Bureaucrat	thiery = Bureaucrat("Thiery", 3);
		Bureaucrat	thiery_copy = thiery;
		Bureaucrat	sophie = Bureaucrat("Sophie", 150);
		Bureaucrat	lou = Bureaucrat("Lou", 20);

		ShrubberyCreationForm	f1 = ShrubberyCreationForm("campus");
		RobotomyRequestForm		f2 = RobotomyRequestForm("a rat");
		PresidentialPardonForm	f3 = PresidentialPardonForm("Captain Sparrow");

		thiery.executeForm(f1);
		sophie.signForm(f1);
		thiery.signForm(f1);
		sophie.executeForm(f1);
		thiery.executeForm(f1);

		lou.signForm(f2);
		lou.executeForm(f2);

		lou.signForm(f3);
		lou.executeForm(f3);

		PresidentialPardonForm	f4 = f3;
		thiery.signForm(f4);
		thiery.executeForm(f4);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
