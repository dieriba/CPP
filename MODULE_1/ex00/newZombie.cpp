#include "./includes/Zombie.hpp"

Zombie* Zombie::newZombie(std::string name)
{
    Zombie* zombie = new (std::nothrow) Zombie(name);
    if (!zombie)
        return (zombie);
    return (zombie);
}