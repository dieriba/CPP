#include "./includes/Zombie.hpp"

void Zombie::randomChump(std::string name)
{
    Zombie zombie(name);
    this -> announce();
}