#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP
#include <string>
#include "Weapon.hpp"
class HumanB
{
    public:
        void attack();
        HumanB(std::string name);
        void setWeapon(Weapon& weapon);
    private:
        std::string name;
        Weapon* weapon;
        
};
#endif