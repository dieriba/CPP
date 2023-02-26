#ifndef __INTERN_HPP_
#define __INTERN_HPP_
#include <string>
class AForm;

typedef struct form
{
    std::string _name;
    AForm* (*make)(const std::string& target);
} form;


#define MAX_LEN_FORM 3

class Intern
{
    public:
        Intern();
        Intern(const std::string& name, const std::string& target);
        Intern(const Intern& rhs);
        Intern& operator=(const Intern& rhs);
        ~Intern();

        static AForm* createRobotomyForm(const std::string& name);
        static AForm* createShrubberyForm(const std::string& name);
        static AForm* createPresidentialForm(const std::string& name);
        AForm* makeForm(const std::string& name, const std::string& target);
        void initForm(void);
    private:
        form _form [MAX_LEN_FORM];
        const std::string _name;
        const std::string _target;
};
#endif