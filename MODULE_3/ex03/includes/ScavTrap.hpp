#ifndef __SCAV_TRAP_HPP
#define __SCAV_TRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
    public:
        void attack(const std::string& target);
        void guardGate(void);
        ScavTrap(std::string name);
        ScavTrap();
        ScavTrap(const ScavTrap& rhs);
        ~ScavTrap();
        ScavTrap& operator=(const ScavTrap& rhs);
};
#endif