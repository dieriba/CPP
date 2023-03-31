#include "./includes/AMateria.hpp"
#include "./includes/ICharacter.hpp"
/*-----------------------------------CONSTRUCTOR/DESTRUCTOR-----------------------------------*/
AMateria::AMateria():type("AMateria"){};
AMateria::AMateria(const std::string & type):type(type){};
AMateria::~AMateria(){std::cout << "AMateria Destructor Called\n";};
/*-----------------------------------CONSTRUCTOR/DESTRUCTOR-----------------------------------*/

/*-----------------------------------CONSTRUCTOR/DESTRUCTOR-----------------------------------*/
const std::string& AMateria::getType() const {return type;};
void AMateria::use(ICharacter& target)
{
    std::cout << "Action toward" << target.getName()
              << " is not defined" << std::endl;
}
/*-----------------------------------CONSTRUCTOR/DESTRUCTOR-----------------------------------*/
