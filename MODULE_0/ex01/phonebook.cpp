#include "./includes/phonebook.hpp"

void	print_(std::string line)
{
	std::cout << line << std::endl;
}

PhoneBook::PhoneBook(int i)
{
	this -> i = i;
}

void PhoneBook::search_contact(void)
{
	std::string line;
	int	number;
	std::cout << "Enter the index of the contact you want more info" << std::endl;
	if (!getOneLine(line))
	{
		std::cout << "Error with index" << std::endl;
		return ;
	}
	number = line[0] - 48;
	std::cout << "Here are the asked informations for" << std::endl;
	this -> contacts[number].show_info();
}

void PhoneBook::display_all_contacts(void)
{
	int	from = 0;
	int to = this -> i;
	std::cout 
        << "|" << std::setw(10) << "Index"
        << "|" << std::setw(10) << "First Name"
        << "|" << std::setw(10) << "Last Name"
        << "|" << std::setw(10) << "Nick Name"
        << std::endl;
	while (from <= to)
	{
		std::cout 
			<< std::setw(10) << this -> contacts[from].get_index()
			<< std::setw(10) << this -> contacts[from].get_first_name()
			<< std::setw(10) << this -> contacts[from].get_last_name()
			<< std::setw(10) << this -> contacts[from].get_nickname()
			<< std::endl;
		from++;
	}
	this -> search_contact();
}

int	PhoneBook::clean_contact(void)
{
	this -> contacts[this -> i].clean();
	return (1);
}

int PhoneBook::add_contact(void)
{
	std::string	info;
	int	i = this -> i;
	print_("Enter the contact firstname's");
	if (!getOneLine(info))
		return (this -> clean_contact());
	this -> contacts[i].set_first_name(info);
	print_("Enter the contact lastname's");
	if (!getOneLine(info))
		return (this -> clean_contact());
	this -> contacts[i].set_last_name(info);
	print_("Enter the contact nickname's");
	if (!getOneLine(info))
		return (this -> clean_contact());
	this -> contacts[i].set_nick_name(info);
	print_("Enter the contact phonenumber's");
	if (!getOneLine(info))
		return (this -> clean_contact());
	this -> contacts[i].set_phone_number(info);
	print_("Enter the contact darkest secret's");
	if (!getOneLine(info))
		return (this -> clean_contact());
	this -> contacts[i].set_darkest_secret(info);
	this -> contacts[i].set_index(i);
	i++;
	i = 8 ? 7 : i;
	return (0);
}