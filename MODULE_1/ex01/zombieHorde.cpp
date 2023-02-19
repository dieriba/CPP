#include "./includes/Zombie.hpp"
#include "./includes/Zombie.h"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie *zombie = new (std::nothrow) Zombie[N];
    if (!zombie)
        return (zombie);
    for (int i = 0; i < N; i++)
        zombie[i].setZombieName(name);
    return (zombie);
}

void    deleteZombieHorde(Zombie *zombie)
{
    if (!zombie)
        return ;
    delete[] zombie;
}

void hordeAnnoucement(int numOfZombies, Zombie* zombie)
{
    for (int i = 0; i < numOfZombies; i++)
        zombie[i].announce();
}