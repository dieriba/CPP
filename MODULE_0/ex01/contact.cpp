# include "./includes/contact.hpp"

void Contact::show_info(void)
{
	std::cout << "index: " << this -> _index << std::endl;
	std::cout << "last_name: " << this -> _last_name << std::endl;
	std::cout << "first_name: " << this -> _first_name << std::endl;
	std::cout << "phone_number: " << this -> _phone_number << std::endl;
	std::cout << "darkset_secret: " << this -> _darkest_secret << std::endl;
}

void Contact::set_index(int index)
{
	this -> _index = index;
}

void Contact::set_last_name(std::string& _last_name)
{
	this -> _last_name = _last_name;
}

void Contact::set_first_name(std::string& _first_name)
{
	this -> _first_name = _first_name;
}

void Contact::set_nick_name(std::string& _nick_name)
{
	this -> _nick_name = _nick_name;
}

void Contact::set_phone_number(std::string& _phone_number)
{
	this -> _phone_number = _phone_number;
}

void Contact::set_darkest_secret(std::string& _darkest_secret)
{
	this -> _darkest_secret = _darkest_secret;
}

std::string Contact::get_last_name(void)
{
	return (this -> _last_name);
}

std::string Contact::get_first_name(void)
{
	return (this -> _first_name);
}

std::string Contact::get_nickname(void)
{
	return (this -> _nick_name);
}

std::string Contact::get_darkset_secret(void)
{
	return (this -> _darkest_secret);
}

std::string Contact::get_phone_number(void)
{
	return (this -> _phone_number);
}
int	Contact::get_index(void)
{
	return (this -> _index);
}