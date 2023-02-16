#include "./includes/phonebook.hpp"

void	print_and_get_line(std::string line, std::string& info)
{
	if (std::cin)
	{
		std::cout << line;
		getline(std::cin, info);
	}
}

PhoneBook::PhoneBook(int i)
{
	this -> _i = i;
}

void PhoneBook::search_contact(void)
{
	std::string line;
	int	number;
	std::cout << "Enter the index of the contact you want more info: ";
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
	int to = this -> _i + (this -> _i == 6);
	std::cout 
        << "|" << std::setw(10) << "Index"
        << "|" << std::setw(10) << "First Name"
        << "|" << std::setw(10) << "Last Name"
        << "|" << std::setw(10) << "Nick Name"
        << std::endl;
	while (from < to)
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

int	PhoneBook::check_valid_info(std::string info[5])
{
	int	i = -1;
	while (++i < 5)
		if (info[i].length() == 0 || is_blank(info[i]))
			return(1);
	return (0);
}
int PhoneBook::add_contact(void)
{
	std::string	info[5];
	int	i = this -> _i;
	print_and_get_line("Enter the contact lastname's: ", info[0]);
	print_and_get_line("Enter the contact firstname's: ", info[1]);
	print_and_get_line("Enter the contact nickname's: ", info[2]);
	print_and_get_line("Enter the contact phonenumber's: ", info[3]);
	print_and_get_line("Enter the contact darkest secret's: ", info[4]);
	if (!std::cin)
		std::cout << std::endl;
	if (this -> check_valid_info(info))
		return (1);
	this -> contacts[i].set_last_name(info[0]);
	this -> contacts[i].set_first_name(info[1]);
	this -> contacts[i].set_nick_name(info[2]);
	this -> contacts[i].set_phone_number(info[3]);
	this -> contacts[i].set_darkest_secret(info[4]);
	this -> contacts[i].set_index(i);
	this -> _i++;
	this -> _i = (this -> _i == 7) ? 6 : this -> _i;
	return (0);
}