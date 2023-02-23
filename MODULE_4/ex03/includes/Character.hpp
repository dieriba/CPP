#include "utility.h"
#ifndef __CHARACTER_HPP_
#define __CHARACTER_HPP_

#include "ICharacter.hpp"
class AMateria;
typedef struct AMateria_collector _collector;
typedef struct AMateria_collector
{
    AMateria* collector;
    _collector* next;
} _collector;

class Character: public ICharacter
{
    public:
        Character();
        Character(const std::string& name);
        Character(const Character& player);
        Character& operator=(const Character& player);
        ~Character();

        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        std::string const & getName() const;
        void giveAmateriaItemLeftOver(const Character& rhs);
        void cleanLeftOver(void);
        void addLeftOver(int idx);
        void printEquippedMateria();
        void printLeftOverMateria();
    private:
        std::string name;
        int          i;
        _collector*  collector;
        AMateria*   items[5];
};
#endif