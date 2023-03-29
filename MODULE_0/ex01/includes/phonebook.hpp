# include "main.h"
# include "contact.hpp"

# ifndef _PHONEBOOK_HPP
# define _PHONEBOOK_HPP
class PhoneBook
{
    public:
        PhoneBook();
        Contact contacts[8];
        int add_contact();
        void display_all_contacts();
        void search_contact(void);
        int	check_valid_info(std::string info[5]);
    private:
        int _i;
};
# endif