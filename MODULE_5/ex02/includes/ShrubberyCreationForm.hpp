#ifndef __SHRUBBERY_CREATION_FORM_HPP_
#define __SHRUBERRY_CREATION_FORM_HPP_
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& rhs);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
        ~ShrubberyCreationForm();

        const std::string& getTarget(void) const;
        void formMessage(void) const;
        const std::string target;
};
#endif