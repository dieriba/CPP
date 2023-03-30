#include "./includes/FragTrap.hpp"

/*------------------------CONSTRUCTOR DESTRUCTOR------------------------*/

FragTrap::FragTrap():ClapTrap("nobody")
{
    _health = 100;
    _energy = 100;
    _damage = 30;
    std::cout << "FragTrap " << _name << " has been created"
              << " with " << _health << " healths points, "
              << _energy << " energy points and " << _damage << " damage points."
              << std::endl;
}

FragTrap::FragTrap(const std::string& name):ClapTrap(name)
{
    _health = 100;
    _energy = 100;
    _damage = 30;
    std::cout << "FragTrap " << _name << " has been created"
              << " with " << _health << " healths points, "
              << _energy << " energy points and " << _damage << " damage points."
              << std::endl;
}

FragTrap::FragTrap(const FragTrap& rhs):ClapTrap(rhs)
{
    _health = 100;
    _energy = 100;
    _damage = 30;
};

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
    if (this == &rhs)
        return (*this);
    _name = rhs.getName();
    _health = rhs.getHealthValue();
    _energy = rhs.getEnergyValue();
    _damage = rhs.getDamagePoints();
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "Unfortunately FragTrap " << _name << " is no more" << std::endl;
}
/*------------------------CONSTRUCTOR DESTRUCTOR------------------------*/


/*------------------------MEMBER FUNCTION------------------------*/

void FragTrap::attack(const std::string& target)
{
    if (printState()) return ;
    _energy -= 1;
    std::cout << "FragTrap " << _name << " attacks "
              << target << " , causing " << _damage << " points of damage!"
              << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name
              << " has accepted the high fives request!!!" << std::endl;
}
/*------------------------MEMBER FUNCTION------------------------*/
