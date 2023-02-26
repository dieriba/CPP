#ifndef __PRESISDENTIAL_PARDON_FORM_HPP__
#define __PRESISDENTIAL_PARDON_FORM_HPP__
#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& rhs);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
        ~PresidentialPardonForm();

        void formMessage(void) const;
        const std::string& getTarget(void) const;
        private:
            const std::string target;
};
#endif