#include "./includes/ClapTrap.hpp"
#include "./includes/ScavTrap.hpp"
#include "./includes/FragTrap.hpp"

int	main(void)
{
	ClapTrap	bob = ClapTrap("Bob");

	bob.attack("a worm");
	bob.takeDamage(9);

	FragTrap	bib = FragTrap("Bib");
	//FragTrap	bubs[2];
	//FragTrap	bab = bib;

	bib.attack("a human");
	bib.highFivesGuys();
	bib.beRepaired(5);
}