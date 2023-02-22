#include "./includes/Animal.hpp"

/*-------------------------------------CONSTRUCTOR/DESTRUCTOR-------------------------------------*/
Animal::Animal():type("no type")
{std::cout << "Animal constructor called\n";}
Animal::Animal(const Animal& rhs):type(rhs.getType()){};
Animal::~Animal(){std::cout << "Animal destructor called\n";}
/*-------------------------------------CONSTRUCTOR/DESTRUCTOR-------------------------------------*/
/*-------------------------------------OPERATOR OVERLOAD-------------------------------------*/
Animal& Animal::operator=(const Animal &rhs){(void)rhs; return (*this);}
/*-------------------------------------OPERATOR OVERLOAD-------------------------------------*/

void Animal::makeSound() const {std::cout << "What sound should I make\n";}
const std::string& Animal::getType(void) const {return type;}