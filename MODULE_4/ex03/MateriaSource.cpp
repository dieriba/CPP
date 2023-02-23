#include "./includes/MateriaSource.hpp"
#include "./includes/AMateria.hpp"
#include "./includes/Ice.hpp"
#include "./includes/Cure.hpp"
/*-----------------------------------CONSTRUCTOR/DESTRUCTOR-----------------------------------*/
MateriaSource::MateriaSource():i(0)
{
    for (size_t i = 0; i < 5; i++)
        materia[i] = 0;
    
};
MateriaSource::MateriaSource(const MateriaSource& rhs)
{
    for (size_t i = 0; i < 5; i++)
    {
        if (rhs.materia[i])
            materia[i] = rhs.materia[i] -> clone();
        else
            materia[i] = 0; 
    }
};
MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
    for (size_t i = 0; i < 5; i++)
    {
        if (materia[i])
            delete materia[i];
        if (rhs.materia[i])
            materia[i] = rhs.materia[i] -> clone();
        else
            materia[i] = 0; 
    } 
    return (*this);
};
MateriaSource::~MateriaSource()
{
    int i = -1;
    while (materia[++i])
        delete materia[i];
  //  std::cout << "AMateria Destructor Called\n";
};
/*-----------------------------------CONSTRUCTOR/DESTRUCTOR-----------------------------------*/

/*-----------------------------------MEMBER/FUNCTION-----------------------------------*/

void MateriaSource::learnMateria(AMateria *item)
{
    if (item == NULL)
        return ;
    if (i == 4 && item)
    {
        delete item;
        return ;
    }
    materia[i++] = item;
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
    int i = -1;
    while (materia[++i])
    {
        if (type == materia[i] -> getType())
            return (materia[i] -> clone());
    }
    return (0);
}
/*-----------------------------------MEMBER/FUNCTION-----------------------------------*/
