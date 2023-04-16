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
	Bureaucrat	dieri;
	Bureaucrat dieri_copy;
	Bureaucrat sophie;
	Bureaucrat lou;
	
	Form f1,f2,f3;
	try
	{
	 	dieri = Bureaucrat("dieri", 3);
		dieri_copy = dieri;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		sophie = Bureaucrat("Sophie", 150);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		lou = Bureaucrat("Lou", 20);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		f1 = Form("f1", 75, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		f2 = Form("f2", 2, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		f3 = Form("f3", 20, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
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
		std::cerr << e.what() << std::endl;
	}

	std::cout << "BeSigned: dieri sign F2: ";
	try
	{
		f2.beSigned(dieri);
		std::cout << "OK" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	dieri_copy.upGrade();

	std::cout << "BeSigned: Thierry_copy sign F2: ";
	try
	{
		f2.beSigned(dieri_copy);
		std::cout << "OK" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "SignForm: Lou sign F3: ";
	try
	{
		lou.signForm(f3);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}