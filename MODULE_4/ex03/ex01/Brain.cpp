#include "./includes/Brain.hpp"

/*-------------------------------------CONSTRUCTOR/DESTRUCTOR-------------------------------------*/
Brain::Brain(){std::cout << "Brain constructor called\n";}
Brain::Brain(const Brain& rhs)
{
    (void)rhs;
    std::cout << "Brain copy constructor called\n";
};
Brain::~Brain(){std::cout << "Brain destructor called\n";}
/*-------------------------------------CONSTRUCTOR/DESTRUCTOR-------------------------------------*/
/*-------------------------------------OPERATOR OVERLOAD-------------------------------------*/
Brain& Brain::operator=(const Brain &rhs)
{
    (void)rhs;
    std::cout << "Brain copy assignement constructor called\n";return (*this);
}
/*-------------------------------------OPERATOR OVERLOAD-------------------------------------*/