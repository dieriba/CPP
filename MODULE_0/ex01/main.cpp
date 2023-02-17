#include "./includes/main.h"
#include "./includes/contact.hpp"
#include "./includes/phonebook.hpp"

int main(void)
{
    PhoneBook   phonebook(0);
    std::string action;

   while (1)
    {
        std::cout 
            << "What action do you want to do : ADD, SEARCH or EXIT" 
            << std::endl
            << "action: ";
        if(!getOneLine(action))
            break;
        else if (action == "ADD")
            phonebook.add_contact();
        else if (action == "SEARCH")
            phonebook.display_all_contacts();
        else if (action == "EXIT")
            break ;
    }
}