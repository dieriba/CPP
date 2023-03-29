#include "./includes/HumanB.hpp"
#include "./includes/Weapon.hpp"
#include <iostream>
HumanB::HumanB(const std::string& name):_name(name),_weapon(NULL){};
void HumanB::setWeapon(Weapon& weapon){_weapon = &weapon;};
void HumanB::attack(void) const
{
    if (_weapon == NULL) return ;
    std::cout << _name << " attack with their " << _weapon -> getType() << std::endl;
}