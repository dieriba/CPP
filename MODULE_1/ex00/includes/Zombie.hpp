# ifndef __ZOMBIE_HPP_
# define __ZOMBIE_HPP_
#include <string>
class Zombie
{
    public:
        Zombie();
        Zombie(const std::string& name); 
        void announce(void);
        ~Zombie();
    private:
        std::string _name;
};

#endif