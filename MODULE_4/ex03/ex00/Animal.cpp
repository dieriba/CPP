#include "./includes/Animal.hpp"
/*-------------------------------------------CONSTRUCTOR/DESTRUCTOR-------------------------------------------*/
Animal::Animal():type("Animal"){std::cout << "Animal constructor called\n";}
Animal::Animal(const Animal& rhs):type(rhs.getType()){};
Animal& Animal::operator=(const Animal& rhs)
{
    type = rhs.getType();
    return *this;
};
Animal::~Animal(){std::cout << "Animal destructor called\n";}
/*-------------------------------------------CONSTRUCTOR/DESTURCTOR-------------------------------------------*/
void Animal::makeSound() const {std::cout << "What sound should I make\n";}
const std::string& Animal::getType(void) const {return type;}