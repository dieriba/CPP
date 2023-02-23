#include "utility.h"
#ifndef __IMATERIA_SOURCE_HPP_
#define __IMATERIA_SOURCE_HPP_
class AMateria;
class IMateriaSource
{
    public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif