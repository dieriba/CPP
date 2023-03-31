#include "./includes/Cat.hpp"

/*-------------------------------------------CONSTRUCTOR/DESTRUCTOR-------------------------------------------*/
Cat::Cat():type("Cat"){std::cout << "Cat constructor called\n";}
Cat::Cat(const Cat& rhs):type(rhs.getType()){};
Cat& Cat::operator=(const Cat& rhs)
{
    type = rhs.getType();
    return *this;
};
Cat::~Cat(){std::cout << "Cat destructor called\n";}
/*-------------------------------------------CONSTRUCTOR/DESTRUCTOR-------------------------------------------*/
void Cat::makeSound() const {std::cout << "MEOWWWWW!!!!!!!!\n";}
const std::string& Cat::getType(void) const {return type;};