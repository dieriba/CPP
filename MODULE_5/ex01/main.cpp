#include "./includes/Bureaucrat.hpp"
#include "./includes/Form.hpp"

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    std::cout << bureaucrat.getName() << " bureaucrat grade is "
              << bureaucrat.getGrade() << std::endl;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    std::cout << form.getName() << " Form grade is "
              << form.getGrade() << " Exec grade is : "
              << form.getExgrade() << " isSigned value: "
              << form.getIsSigned() << std::endl;
    return os;
}

int	main()
{
	Bureaucrat	thiery = Bureaucrat("Thiery", 3);
	Bureaucrat	thiery_copy = thiery;
	Bureaucrat	sophie = Bureaucrat("Sophie", 150);
	Bureaucrat	lou = Bureaucrat("Lou", 20);

	Form		f1 = Form("f1", 75, 1);
	Form		f2 = Form("f2", 2, 1);
	Form		f3 = Form("f3", 20, 1);

	std::cout << "Create a form with incorect grade: ";
	try
	{
		Form	f4 = Form("f4", 0, 184);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "SignForm: Sophie sign F1: ";
	try
	{
		sophie.signForm(f1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "BeSigned: Thiery sign F2: ";
	try
	{
		f2.beSigned(thiery);
		std::cout << "OK" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	thiery_copy.upGrade();

	std::cout << "BeSigned: Thierry_copy sign F2: ";
	try
	{
		f2.beSigned(thiery_copy);
		std::cout << "OK" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "SignForm: Lou sign F3: ";
	try
	{
		lou.signForm(f3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}