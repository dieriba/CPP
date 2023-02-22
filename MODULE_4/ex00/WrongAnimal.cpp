#include "./includes/WrongAnimal.hpp"


WrongAnimal::WrongAnimal():type("no type")
{std::cout << "WrongAnimal constructor called\n";}
WrongAnimal::~WrongAnimal(){std::cout << "WrongAnimal destructor called\n";}
void WrongAnimal::makeSound() const {std::cout << "What sound should I make\n";}
const std::string& WrongAnimal::getType(void) const {return type;}