#ifndef __SCAV_TRAP_HPP
#define __SCAV_TRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(const std::string& name);
        ~ScavTrap();

        ScavTrap(const ScavTrap& rhs);
        ScavTrap& operator=(const ScavTrap& rhs);
        
        /*PUBLIC MEMBER*/
        void attack(const std::string& target);
        void guardGate(void);
};
#endif