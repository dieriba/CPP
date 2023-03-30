#include "./includes/Zombie.hpp"
#include "./includes/Zombie.h"


int main(void)
{
    std::string f = "fanta";
    Zombie z1(f);
    Zombie *zombie = newZombie("nabintou");
    if (!zombie)
        return (1);
    z1.announce();
    zombie -> announce();
    randomChump("dieriba");
    delete zombie;
}