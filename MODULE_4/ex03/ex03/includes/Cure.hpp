#include "utility.h"
#ifndef _CURE_HPP_
#define _CURE_HPP_

#include "AMateria.hpp"
class AMateria ;
class ICharacter;
class Cure: public AMateria
{
    public:
        Cure();
        Cure(const Cure& rhs);
        Cure& operator=(const Cure& rhs);
        ~Cure();

        AMateria* clone(void) const;
        void use(ICharacter& target);
};

#endif