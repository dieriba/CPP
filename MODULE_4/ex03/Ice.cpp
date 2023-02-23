#include "./includes/Ice.hpp"

/*-----------------------------------CONSTRUCTOR/DESTRUCTOR-----------------------------------*/
Ice::Ice():AMateria("ice"){};
Ice::Ice(const Ice& rhs):AMateria("ice"){(void)rhs;};
Ice& Ice::operator=(const Ice& rhs){(void)rhs; return (*this);};
Ice::~Ice(){std::cout << "Ice Destructor Called\n";};
/*-----------------------------------CONSTRUCTOR/DESTRUCTOR-----------------------------------*/

/*-----------------------------------MEMBER/FUNCTION-----------------------------------*/
AMateria* Ice::clone(void) const{return new (std::nothrow) Ice();};
void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at "
              << target.getName() << " *"
              << std::endl;
}

/*-----------------------------------MEMBER/FUNCTION-----------------------------------*/
