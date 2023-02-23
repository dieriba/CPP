#include "utility.h"
#ifndef _AMATERIA_HPP_
#define _AMATERIA_HPP_

class ICharacter;
class AMateria
{
    public:
        AMateria(std::string const & type);
        AMateria();
        virtual ~AMateria();
        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone(void) const = 0;
        virtual void use(ICharacter& target);
    protected:
        std::string type;
};

#endif