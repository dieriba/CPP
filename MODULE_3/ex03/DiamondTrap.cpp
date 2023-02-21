#include "./includes/DiamondTrap.hpp"


/*------------------------CONSTRUCTOR DESTRUCTOR------------------------*/

DiamondTrap::DiamondTrap():ClapTrap(),FragTrap(),ScavTrap()
{
    this -> _name = "nobody";
    this -> _health = FragTrap::_health;
    this -> _energy = ScavTrap::_energy;
    this -> _damage = FragTrap::_damage;
    ClapTrap::_name = "nobody_clap_name";
    std::cout << "DiamondTrap " << _name << " has been created"
              << " with " << _health << " healths points, "
              << _energy << " energy points and " << _damage << " damage points."
              << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
:ClapTrap(name + "_clap_name"),FragTrap(name),ScavTrap(name)
{
    this -> _name = name;
    this -> _health = FragTrap::_health;
    this -> _energy = FragTrap::_energy;
    this -> _damage = FragTrap::_damage;
    std::cout << "DiamondTrap " << _name << " has been created"
              << " with " << _health << " healths points, "
              << _energy << " energy points and " << _damage << " damage points."
              << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& rhs)
:ClapTrap(rhs),FragTrap(rhs),ScavTrap(rhs)
{
    this -> _name = rhs._name;
    this -> _health = FragTrap::_health;
    this -> _energy = ScavTrap::_energy;
    this -> _damage = FragTrap::_damage;
};

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs)
{
    if (this == &rhs)
        return (*this);
    this -> ClapTrap::_name = rhs.ClapTrap::_name;
    this -> _name = rhs.getName();
    this -> _health = rhs.getHealthValue();
    this -> _energy = rhs.getEnergyValue();
    this -> _damage = rhs.getDamagePoints();
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "Unfortunately DiamondTrap "
              << _name << " is no more"
              << std::endl;
}
/*------------------------CONSTRUCTOR DESTRUCTOR------------------------*/



/*--------------------PUBLIC MENBER FUNCTION--------------------*/
void DiamondTrap::whoAmI(void)
{
    std::cout << "Am i " << ClapTrap::_name
              << " or Am i " << this -> _name
              << " that is the question..." << std::endl;
}
void DiamondTrap::attack(const std::string& target) {ScavTrap::attack(target);}
/*--------------------PUBLIC MENBER FUNCTION--------------------*/