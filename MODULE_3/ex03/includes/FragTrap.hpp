#ifndef __FRAG_TRAP_HPP
#define __FRAG_TRAP_HPP
#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
    public:
        FragTrap(std::string name);
        FragTrap();
        FragTrap(const FragTrap& rhs);
        ~FragTrap();
        FragTrap& operator=(const FragTrap& rhs);

        void attack(const std::string& target);
        void guardGate(void);
        void highFivesGuys(void);
};
#endif