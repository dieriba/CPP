#include "./includes/Zombie.hpp"
#include "./includes/Zombie.h"

Zombie::Zombie(std::string& name)
{
    this -> name = name;
}

Zombie::Zombie(void) {}

Zombie::~Zombie(void)
{
    std::cout << "Zombie named: "
              << this -> name 
              << " died !"
              << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this -> name << ": "
              << "BraiiiiiiinnnzzzZ..."
              << std::endl;
}

void Zombie::setZombieName(std::string name)
{
    this -> name = name;
}
