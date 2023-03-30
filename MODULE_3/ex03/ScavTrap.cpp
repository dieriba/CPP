#include "./includes/ScavTrap.hpp"

/*------------------------CONSTRUCTOR DESTRUCTOR------------------------*/

ScavTrap::ScavTrap():ClapTrap("nobody")
{
    _health = 100;
    _energy = 50;
    _damage = 20;
    std::cout << "ScavTrap " << _name << " has been created"
              << " with " << _health << " healths points, " << _energy
              << " energy points and " << _damage << " damage points."
              << std::endl;
}

ScavTrap::ScavTrap(const std::string& name):ClapTrap(name)
{
    _health = 100;
    _energy = 50;
    _damage = 20;
    std::cout << "ScavTrap " << _name << " has been created"
              << " with " << _health << " healths points, "
              << _energy << " energy points and " << _damage << " damage points."
              << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& rhs):ClapTrap(rhs)
{
    _health = 100;
    _energy = 50;
    _damage = 20;
};

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
    if (this == &rhs)
        return (*this);
    _name = rhs.getName();
    _health = rhs.getHealthValue();
    _energy = rhs.getEnergyValue();
    _damage = rhs.getDamagePoints();
    return (*this);
}

ScavTrap::~ScavTrap() {std::cout << "Unfortunately ScavTrap " << _name << " is no more" << std::endl;}
/*------------------------CONSTRUCTOR DESTRUCTOR------------------------*/


/*------------------------MEMBER FUNCTION------------------------*/

void ScavTrap::attack(const std::string& target)
{
    if (printState()) return ;
    _energy--;
    std::cout << "ScavTrap " << _name << " attacks "
              << target << " , causing " << _damage << " points of damage!"
              << std::endl;
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << _name
              << " has now enabled the keeper mode" << std::endl;
}
/*------------------------MEMBER FUNCTION------------------------*/
