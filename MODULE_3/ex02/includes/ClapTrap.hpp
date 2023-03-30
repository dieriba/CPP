#ifndef _CLAP_TRAP_H
#define _CLAP_TRAP_H
#include <string>
#include <iostream>
class ClapTrap
{
    public:
        ClapTrap();
        ClapTrap(const std::string& name);
        ~ClapTrap();

        ClapTrap(const ClapTrap& rhs);
        ClapTrap& operator=(const ClapTrap& rhs);
        
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);


        unsigned int getHealthValue(void) const;
        unsigned int getEnergyValue(void) const ;
        unsigned int getDamagePoints(void) const;  
        int printState(void);
        std::string  getName(void) const;
    protected:
        std::string  _name;
        int _health;
        int _energy;
        int _damage;
};
#endif