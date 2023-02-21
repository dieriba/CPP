#ifndef _DIAMOND_TRAP_HPP
#define _DIAMOND_TRAP_HPP
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
    public:
        DiamondTrap();
        ~DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap& rhs);

        DiamondTrap& operator=(const DiamondTrap& rhs);
        void attack(const std::string& target);
        void whoAmI(void);
    private:
        std::string _name;
};

#endif