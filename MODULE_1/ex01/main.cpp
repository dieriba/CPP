#include "./includes/Zombie.hpp"
#include "./includes/Zombie.h"

int main ()
{
    int numOfZombies = 5;
    std::string dieri = "dieriba";
    Zombie* zombie = zombieHorde(numOfZombies, dieri);
    if (!zombie)
        return (1);
    hordeAnnoucement(numOfZombies, zombie);
    deleteZombieHorde(zombie);
}