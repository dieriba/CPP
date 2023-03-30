#include "./includes/ClapTrap.hpp"
/*------------------------CONSTRUCTOR DESTRUCTOR------------------------*/

ClapTrap::ClapTrap()
:_name("nobody"),_health(10),_energy(10),_damage(0)
{
    std::cout << "ClapTrap " << _name << " has been created"
              << " with " << _health << " healths points, " << _energy
              << " energy points and " << _damage << " damage points."
              << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
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
    std::cout << "Unfortunately ClapTrap " << _name << " is no more" << std::endl;
}
/*------------------------CONSTRUCTOR DESTRUCTOR------------------------*/

/*------------------------OVERLOAD OPERATOR------------------------*/
ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
    if (this == &rhs)
        return (*this);
    _name = rhs.getName();
    _health = rhs.getHealthValue();
    _energy = rhs.getEnergyValue();
    _damage = rhs.getDamagePoints();
    return (*this);
}
/*------------------------OVERLOAD OPERATOR------------------------*/

/*------------------------PUBLIC MEMBER FUNCTION------------------------*/
std::string ClapTrap::getName(void) const {return _name;};
unsigned int ClapTrap::getDamagePoints(void) const {return _damage;} 
unsigned int ClapTrap::getHealthValue(void) const {return _health;}
unsigned int ClapTrap::getEnergyValue(void) const {return _energy;}

int ClapTrap::printState(void)
{
    if (_health > 0 && _energy > 0)
        return (0);
    if (_health <= 0 && _energy <= 0)
        std::cout << "ClapTrap " << _name << " has no energy left nor health left." << std::endl;
    else if (_health <= 0)
        std::cout << "ClapTrap " << _name << " has no more health left." << std::endl;
    else if (_energy <= 0)
        std::cout << "ClapTrap " << _name << " has no more energy left." << std::endl;
    return (1);
}

void ClapTrap::attack(const std::string& target)
{
    if (printState()) return ;
    _energy--;
    std::cout << "ClapTrap " << getName() << " attacks "
              << target << " , causing " << getDamagePoints() << " points of damage!"
              << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (printState()) return ;
    _health = (_health - amount) < 0 ? 0 : (_health - amount);
    std::cout << "ClapTrap " << _name << " took "
              << amount << " of damage points" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (printState()) return ;
    _energy--;
    _health += amount;
    std::cout << "ClapTrap " << _name << "has gained back "
              << amount << " health points" << std::endl;
}

/*------------------------PUBLIC MEMBER FUNCTION------------------------*/
