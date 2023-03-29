#include "./includes/Zombie.hpp"
#include "./includes/Zombie.h"

Zombie::Zombie(const std::string& name):_name(name){};
Zombie::Zombie(void) {};
Zombie::~Zombie(void){std::cout << "Zombie named: " << _name << " died !" << std::endl;}
void Zombie::announce(void) const{std::cout << _name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;}
void Zombie::setZombieName(const std::string& name){_name = name;}
