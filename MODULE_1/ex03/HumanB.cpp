#include "./includes/HumanB.hpp"
#include "./includes/Weapon.hpp"
#include <iostream>
HumanB::HumanB(std::string name)
{
    this -> name = name;
    this -> weapon = NULL;
}

void HumanB::setWeapon(Weapon& weapon)
{
    this -> weapon = &weapon;
}

void HumanB::attack(void)
{
    if (this -> weapon == NULL)
        return ;
    std::cout << this -> name
               << " attack with their "
               << this -> weapon -> getType()
               << std::endl;
}