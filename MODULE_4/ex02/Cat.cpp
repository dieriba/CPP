#include "./includes/Cat.hpp"
/*-------------------------------------CONcSTRUCTOR/DESTRUCTOR-------------------------------------*/
Cat::Cat():Animal()
{
    type = "Cat";
    std::cout << "Cat constructor called\n";
    idea = new (std::nothrow) Brain;
}
Cat::Cat(const Cat& rhs):Animal()
{
    std::cout << "Cat copy constructor called\n";
    type = rhs.type;
    idea = new (std::nothrow) Brain;
};
Cat& Cat::operator=(const Cat& rhs) {(void)rhs; std::cout << "Cat assignement operator called\n"; return (*this);};
Cat::~Cat()
{
    std::cout << "Cat destructor called\n";
    delete idea;
}
/*-------------------------------------CONSTRUCTOR/DESTRUCTOR-------------------------------------*/
void Cat::makeSound() const {std::cout << "MEOWWWWW!!!!!!!!\n";}
const std::string& Cat::getType(void) const {return type;};