# include "Zombie.h"
# ifndef __ZOMBIE_HPP_
# define __ZOMBIE_HPP_

class Zombie
{
    public:
        void announce(void);
        void randomChump(std::string name);
        Zombie* newZombie(std::string name);
        Zombie() = default;
        Zombie(std::string& name); 
        ~Zombie();
    private:
        std::string name;
};

#endif