# include "main.h"
# ifndef _CONTACT_HPP
# define _CONTACT_HPP

class Contact
{
	public:
		void	set_index(const int& index);
		void	set_last_name(const std::string& _last_name);
		void	set_first_name(const std::string& _first_name);
		void	set_nick_name(const std::string& _nick_name);
		void	set_phone_number(const std::string& _phone_number);
		void	set_darkest_secret(const std::string& _darkest_secret);
		void	show_info();
		
		/*GETTER*/
		const std::string&	get_last_name(void) const;
		const std::string&	get_first_name(void) const;
		const std::string&	get_nickname(void) const ;
		const std::string&	get_darkset_secret(void) const;
		const std::string&	get_phone_number(void) const;
		const int&			get_index(void) const;

	private:
		int			_index;
		std::string _last_name;
		std::string _first_name;
		std::string _nick_name;
		std::string _phone_number;
		std::string _darkest_secret;
};
#endif