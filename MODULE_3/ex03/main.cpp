#include "./includes/ClapTrap.hpp"
#include "./includes/ScavTrap.hpp"
#include "./includes/FragTrap.hpp"
#include "./includes/DiamondTrap.hpp"

int	main(void)
{
	//FragTrap	bob = FragTrap("Bob");

	//bob.attack("a worm");
	//bob.takeDamage(9);

	DiamondTrap	bib = DiamondTrap("Bib");
	//DiamondTrap	bubs[2];
	//DiamondTrap	bab = bib;

	bib.whoAmI();
	bib.attack("a human");
	bib.highFivesGuys();
	bib.beRepaired(5);
}