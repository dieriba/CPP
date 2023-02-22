#include "./includes/Cat.hpp"


Cat::Cat():type("Cat")
{std::cout << "Cat constructor called\n";}
Cat::~Cat(){std::cout << "Cat destructor called\n";}
void Cat::makeSound() const {std::cout << "MEOWWWWW!!!!!!!!\n";}
const std::string& Cat::getType(void) const {return type;};