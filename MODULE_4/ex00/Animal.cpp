#include "./includes/Animal.hpp"


Animal::Animal():type("no type")
{std::cout << "Animal constructor called\n";}
Animal::~Animal(){std::cout << "Animal destructor called\n";}
void Animal::makeSound() const {std::cout << "What sound should I make\n";}
const std::string& Animal::getType(void) const {return type;}