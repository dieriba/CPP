#include "./includes/Cure.hpp"
#include "./includes/AMateria.hpp"
#include "./includes/ICharacter.hpp"
/*-----------------------------------CONSTRUCTOR/DESTRUCTOR-----------------------------------*/
Cure::Cure():AMateria("cure"){};
Cure::Cure(const Cure& rhs):AMateria("Cure"){(void)rhs;};
Cure& Cure::operator=(const Cure& rhs){(void)rhs; return (*this);};
Cure::~Cure(){std::cout << "Cure Destructor Called\n";};
/*-----------------------------------CONSTRUCTOR/DESTRUCTOR-----------------------------------*/

/*-----------------------------------MEMBER/FUNCTION-----------------------------------*/
AMateria* Cure::clone(void) const{return new (std::nothrow) Cure();};

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName()
              << "'s wounds *" << std::endl;
}

/*-----------------------------------MEMBER/FUNCTION-----------------------------------*/
