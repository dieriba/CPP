#ifndef __ZOMBIE_H_
#define __ZOMBIE_H_

#include <string>
#include <iostream>
Zombie* zombieHorde(int N, std::string name);
void deleteZombieHorde(Zombie *zombie);
void hordeAnnoucement(int numOfZombies, Zombie* zombie);
#endif