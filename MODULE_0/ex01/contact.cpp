# include "./includes/contact.hpp"

void Contact::show_info(void)
{
	std::cout << "index: " << _index << std::endl;
	std::cout << "last_name: " << _last_name << std::endl;
	std::cout << "first_name: " << _first_name << std::endl;
	std::cout << "phone_number: " << _phone_number << std::endl;
	std::cout << "darkset_secret: " << _darkest_secret << std::endl;
}
/*--------------------------------------------------SETTER---------------------------------------------*/
void Contact::set_index(const int& index){_index = index;}
void Contact::set_last_name(const std::string& last_name){_last_name = last_name;}
void Contact::set_first_name(const std::string& first_name){_first_name = first_name;}
void Contact::set_nick_name(const std::string& nick_name){_nick_name = nick_name;}
void Contact::set_phone_number(const std::string& phone_number){_phone_number = phone_number;}
void Contact::set_darkest_secret(const std::string& darkest_secret){_darkest_secret = darkest_secret;}
/*--------------------------------------------------SETTER---------------------------------------------*/
/*--------------------------------------------------GETTER---------------------------------------------*/
const std::string& Contact::get_last_name(void) const {return _last_name;}
const std::string& Contact::get_first_name(void) const {return _first_name;}
const std::string& Contact::get_nickname(void) const {return _nick_name;}
const std::string& Contact::get_darkset_secret(void) const {return _darkest_secret;}
const std::string& Contact::get_phone_number(void) const {return _phone_number;}
const int&	Contact::get_index(void) const {return _index;}
/*--------------------------------------------------GETTER---------------------------------------------*/