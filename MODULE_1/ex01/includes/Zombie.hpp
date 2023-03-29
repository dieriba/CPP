# ifndef __ZOMBIE_HPP_
# define __ZOMBIE_HPP_
#include <string>
class Zombie
{
    public:
        Zombie();
        Zombie(const std::string& name); 
        ~Zombie();
        void announce(void) const;
        void setZombieName(const std::string& name);
    private:
        std::string _name;
};

#endif