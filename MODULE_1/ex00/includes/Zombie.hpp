# ifndef __ZOMBIE_HPP_
# define __ZOMBIE_HPP_
#include <string>
class Zombie
{
    public:
        void announce(void) const;
        Zombie();
        Zombie(const std::string& name); 
        ~Zombie();
    private:
        std::string _name;
};

#endif