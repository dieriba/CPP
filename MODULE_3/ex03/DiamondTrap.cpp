#include "./includes/DiamondTrap.hpp"


/*------------------------CONSTRUCTOR DESTRUCTOR------------------------*/

DiamondTrap::DiamondTrap():ClapTrap(),FragTrap(),ScavTrap()
{
    _name = "nobody";
    _health = 100;
    _energy = 50;
    _damage = 30;
    ClapTrap::_name = "nobody_clap_name";
    std::cout << "DiamondTrap " << _name << " has been created"
              << " with " << _health << " healths points, "
              << _energy << " energy points and " << _damage << " damage points."
              << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
:ClapTrap(name + "_clap_name"),FragTrap(name + "_frag_name"),ScavTrap(name + "_scav_trap")
{
    _name = name;
    _health = 100;
    _energy = 50;
    _damage = 30;
    std::cout << "DiamondTrap " << _name << " has been created"
              << " with " << _health << " healths points, "
              << _energy << " energy points and " << _damage << " damage points."
              << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& rhs)
:ClapTrap(rhs),FragTrap(rhs),ScavTrap(rhs)
{
    _name = rhs._name;
    _health = 100;
    _energy = 50;
    _damage = 30;
};

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs)
{
    if (this == &rhs)
        return (*this);
    ClapTrap::_name = rhs.ClapTrap::_name;
    _name = rhs.getName();
    _health = rhs.getHealthValue();
    _energy = rhs.getEnergyValue();
    _damage = rhs.getDamagePoints();
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "Unfortunately DiamondTrap " << _name << " is no more" << std::endl;
}
/*------------------------CONSTRUCTOR DESTRUCTOR------------------------*/



/*--------------------PUBLIC MENBER FUNCTION--------------------*/
void DiamondTrap::whoAmI(void)
{
    std::cout << "Am i " << ClapTrap::_name
              << " or Am i " << _name
              << "ScavTrap: " << std::endl
              << " that is the question..." << std::endl;
}
void DiamondTrap::attack(const std::string& target) {ScavTrap::attack(target);}
/*--------------------PUBLIC MENBER FUNCTION--------------------*/