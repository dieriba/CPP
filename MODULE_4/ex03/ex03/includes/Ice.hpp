#include "utility.h"
#ifndef _ICE_HPP_
#define _ICE_HPP_


#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice: public AMateria
{
    public:
        Ice();
        Ice(const Ice& rhs);
        Ice& operator=(const Ice& rhs);
        ~Ice();
        
        AMateria* clone(void) const;
        void use(ICharacter& target);
};
#endif