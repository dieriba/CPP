# include "main.h"
# ifndef _CONTACT_HPP
# define _CONTACT_HPP

class Contact
{
	public:
		void	set_index(int index);
		void	set_last_name(std::string& _last_name);
		void	set_first_name(std::string& _first_name);
		void	set_nick_name(std::string& _nick_name);
		void	set_phone_number(std::string& _phone_number);
		void	set_darkest_secret(std::string& _darkest_secret);
		void	show_info();
		std::string	get_last_name(void);
		std::string	get_first_name(void);
		std::string	get_nickname(void);
		std::string	get_darkset_secret(void);
		std::string	get_phone_number(void);
		int			get_index(void);

	private:
		int			_index;
		std::string _last_name;
		std::string _first_name;
		std::string _nick_name;
		std::string _phone_number;
		std::string _darkest_secret;
};
#endif