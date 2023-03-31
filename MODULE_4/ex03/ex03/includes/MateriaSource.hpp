#include "utility.h"
#ifndef __MATERIASOURCE_HPP_
#define __MATERIASOURCE_HPP_

class IMateriaSource ;
class AMateria ;
#include "IMateriaSource.hpp"
class MateriaSource: public IMateriaSource
{
    public:
        MateriaSource();
        MateriaSource(const MateriaSource& rhs);
        MateriaSource& operator=(const MateriaSource& rhs);
        ~MateriaSource();

        void learnMateria(AMateria *);
        AMateria* createMateria(const std::string& type);
    private:
        AMateria* materia[5];
        int i;
};

#endif