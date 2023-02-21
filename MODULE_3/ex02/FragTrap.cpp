#include "./includes/FragTrap.hpp"

/*------------------------CONSTRUCTOR DESTRUCTOR------------------------*/

FragTrap::FragTrap():ClapTrap("nobody")
{
    this -> _health = 100;
    this -> _energy = 50;
    this -> _damage = 30;
    std::cout << "FragTrap " << _name << " has been created"
              << " with " << _health << " healths points, "
              << _energy << " energy points and " << _damage << " damage points."
              << std::endl;
}

FragTrap::FragTrap(std::string name):ClapTrap(name)
{
    this -> _health = 100;
    this -> _energy = 100;
    this -> _damage = 30;
    std::cout << "FragTrap " << _name << " has been created"
              << " with " << _health << " healths points, "
              << _energy << " energy points and " << _damage << " damage points."
              << std::endl;
}

FragTrap::FragTrap(const FragTrap& rhs):ClapTrap(rhs)
{
    this -> _health = 100;
    this -> _energy = 100;
    this -> _damage = 30;
};

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
    if (this == &rhs)
        return (*this);
    this -> _name = rhs.getName();
    this -> _health = rhs.getHealthValue();
    this -> _energy = rhs.getEnergyValue();
    this -> _damage = rhs.getDamagePoints();
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "Unfortunately FragTrap "
              << _name << " is no more"
              << std::endl;
}
/*------------------------CONSTRUCTOR DESTRUCTOR------------------------*/


/*------------------------MEMBER FUNCTION------------------------*/

void FragTrap::attack(const std::string& target)
{
    if (this -> printState()) return ;
    this -> _energy -= 1;
    std::cout << "FragTrap " << this -> getName() << " attacks "
              << target << " , causing " << this -> getDamagePoints() << " points of damage!"
              << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this -> _name
              << " has accepted the high fives request!!!" << std::endl;
}
/*------------------------MEMBER FUNCTION------------------------*/
