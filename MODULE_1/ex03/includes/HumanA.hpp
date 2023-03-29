#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP
#include <string>
#include "Weapon.hpp"

class HumanA
{
    public:
        HumanA(const std::string& name, Weapon& weapon);
        const Weapon& get_weapon(void) const;
        void attack(void) const;
    private:
        std::string _name;
        Weapon&     _weapon;    
};
#endif
