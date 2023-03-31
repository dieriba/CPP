#include "./includes/WrongAnimal.hpp"
/*-------------------------------------------CONSTRUCTOR/DESTRUCTOR-------------------------------------------*/
WrongAnimal::WrongAnimal():type("WrongAnimal"){std::cout << "WrongAnimal constructor called\n";}
WrongAnimal::WrongAnimal(const WrongAnimal& rhs):type(rhs.getType()){};
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
    type = rhs.getType();
    return *this;
};
WrongAnimal::~WrongAnimal(){std::cout << "WrongAnimal destructor called\n";}
/*-------------------------------------------CONSTRUCTOR/DESTRUCTOR-------------------------------------------*/
void WrongAnimal::makeSound() const {std::cout << "What sound should I make\n";}
const std::string& WrongAnimal::getType(void) const {return type;}