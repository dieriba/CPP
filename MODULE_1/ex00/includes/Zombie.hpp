# ifndef __ZOMBIE_HPP_
# define __ZOMBIE_HPP_
#include <string>
class Zombie
{
    public:
        void announce(void);
        Zombie();
        Zombie(std::string& name); 
        ~Zombie();
    private:
        std::string name;
};

#endif