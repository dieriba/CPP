#include "./includes/ClapTrap.hpp"

int main(void)
{
    ClapTrap d("dieriba");
    ClapTrap b("booba");
    ClapTrap m("moussa");

    d.attack(m.getName());
    b.attack(d.getName());
    d.takeDamage(10);
    d.attack(m.getName());
    b.takeDamage(5);
    m.takeDamage(5);
    m.takeDamage(5);
    b.beRepaired(3);
    b.takeDamage(5);
    b.attack("dieriba");
    b.takeDamage(4);
}