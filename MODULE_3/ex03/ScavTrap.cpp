#include "./includes/ScavTrap.hpp"

/*------------------------CONSTRUCTOR DESTRUCTOR------------------------*/

ScavTrap::ScavTrap():ClapTrap("nobody")
{
    this -> _health = 100;
    this -> _energy = 50;
    this -> _damage = 20;
    std::cout << "ScavTrap " << _name << " has been created"
              << " with " << _health << " healths points, "
              << _energy << " energy points and " << _damage << " damage points."
              << std::endl;
}

ScavTrap::ScavTrap(std::string name):ClapTrap(name)
{
    this -> _health = 100;
    this -> _energy = 50;
    this -> _damage = 20;
    std::cout << "ScavTrap " << _name << " has been created"
              << " with " << _health << " healths points, "
              << _energy << " energy points and " << _damage << " damage points."
              << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& rhs):ClapTrap(rhs)
{
    this -> _health = 100;
    this -> _energy = 50;
    this -> _damage = 20;
};

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
    if (this == &rhs)
        return (*this);
    this -> _name = rhs.getName();
    this -> _health = rhs.getHealthValue();
    this -> _energy = rhs.getEnergyValue();
    this -> _damage = rhs.getDamagePoints();
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "Unfortunately ScavTrap "
              << _name << " is no more"
              << std::endl;
}
/*------------------------CONSTRUCTOR DESTRUCTOR------------------------*/


/*------------------------MEMBER FUNCTION------------------------*/

void ScavTrap::attack(const std::string& target)
{
    if (this -> printState()) return ;
    this -> _energy -= 1;
    std::cout << "ScavTrap " << this -> getName() << " attacks "
              << target << " , causing " << this -> getDamagePoints() << " points of damage!"
              << std::endl;
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << this -> _name
              << " has now enabled the keeper mode" << std::endl;
}
/*------------------------MEMBER FUNCTION------------------------*/
