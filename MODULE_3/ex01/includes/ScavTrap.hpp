#ifndef __SCAV_TRAP_HPP
#define __SCAV_TRAP_HPP
#include "ClapTrap.hpp"
class ScavTrap: public ClapTrap
{
    public:
        ScavTrap();
        ~ScavTrap();
        ScavTrap(const std::string& name);
        
        ScavTrap(const ScavTrap& rhs);
        ScavTrap& operator=(const ScavTrap& rhs);
        
        void attack(const std::string& target);
        void guardGate(void);
};
#endif