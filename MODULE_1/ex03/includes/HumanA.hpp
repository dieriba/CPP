#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP
#include <string>
#include "Weapon.hpp"

class HumanA
{
    public:
        HumanA(std::string name, Weapon& weapon);
        Weapon& get_weapon(void);
        void attack(void);
    private:
        std::string _name;
        Weapon&      _weapon;    
};
#endif
