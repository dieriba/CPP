# include "main.h"
# include "contact.hpp"

# ifndef _PHONEBOOK_HPP
# define _PHONEBOOK_HPP
class PhoneBook
{
    public:
        PhoneBook(int i);
        Contact contacts[8];
        int add_contact();
        void display_all_contacts();
        void search_contact(void);
        int clean_contact();
    private:
        int i;
};
# endif