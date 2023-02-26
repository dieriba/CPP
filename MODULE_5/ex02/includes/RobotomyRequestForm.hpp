#ifndef __ROBOTOMY_REQUEST_FORM_HPP__
#define __ROBOTOMY_REQUEST_FORM_HPP__
#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& rhs);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
        ~RobotomyRequestForm();

        void formMessage(void) const;
        const std::string& getTarget(void) const;
    private:
        const std::string target;
};
#endif