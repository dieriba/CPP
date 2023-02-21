#include "./includes/ClapTrap.hpp"
/*------------------------CONSTRUCTOR DESTRUCTOR------------------------*/
ClapTrap::ClapTrap(std::string name)
:_name(name),_health(10),_energy(10),_damage(0)
{
    std::cout << "ClapTrap " << _name << " has been created"
              << " with " << _health << " healths points, "
              << _energy << " energy points and " << _damage << " damage points."
              << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& rhs)
:_name(rhs.getName()),_health(rhs.getHealthValue())
,_energy(rhs.getEnergyValue()),_damage(rhs.getDamagePoints())
{};

ClapTrap::~ClapTrap()
{
    std::cout << "Unfortunately ClapTrap "
              << _name << " is no more"
              << std::endl;
}
/*------------------------CONSTRUCTOR DESTRUCTOR------------------------*/

/*------------------------OVERLOAD OPERATOR------------------------*/
ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
    if (this == &rhs)
        return (*this);
    this -> _name = rhs.getName();
    this -> _health = rhs.getHealthValue();
    this -> _energy = rhs.getEnergyValue();
    this -> _damage = rhs.getDamagePoints();
    return (*this);
}
/*------------------------OVERLOAD OPERATOR------------------------*/

/*------------------------PUBLIC MEMBER FUNCTION------------------------*/
std::string ClapTrap::getName(void) const {return this -> _name;};
unsigned int ClapTrap::getDamagePoints(void) const {return this -> _damage;} 
unsigned int ClapTrap::getHealthValue(void) const {return this -> _health;}
unsigned int ClapTrap::getEnergyValue(void) const {return this -> _energy;}

int ClapTrap::printState(void)
{
    if (this -> _health > 0 && this -> _energy > 0)
        return (0);
    if (this -> _health <= 0 && this -> _energy <= 0)
        std::cout << "ClapTrap " << this -> _name << " has no energy left nor health left." << std::endl;
    else if (this -> _health <= 0)
        std::cout << "ClapTrap " << this -> _name << " has no more health left." << std::endl;
    else if (this -> _energy <= 0)
        std::cout << "ClapTrap " << this -> _name << " has no more energy left." << std::endl;
    return (1);
}

void ClapTrap::attack(const std::string& target)
{
    if (this -> printState()) return ;
    this -> _energy -= 1;
    std::cout << "ClapTrap " << this -> getName() << " attacks "
              << target << " , causing " << this -> getDamagePoints() << " points of damage!"
              << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this -> printState()) return ;
    this -> _damage = amount;
    if (this -> _health < this -> _damage)
        this -> _health = 0;
    else this -> _health -= amount;
    std::cout << "ClapTrap " << this -> getName()
              << " took " << amount << " of damage points"
              << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this -> printState()) return ;
    this -> _energy--;
    this -> _health += amount;
    std::cout << "ClapTrap " << this -> getName()
              << "has gained back " << amount
              << " health points" << std::endl;
}

/*------------------------PUBLIC MEMBER FUNCTION------------------------*/
