#include "./includes/Dog.hpp"
/*-------------------------------------CONSTRUCTOR/DESTRUCTOR-------------------------------------*/
Dog::Dog():Animal()
{
    type = "dog";
    std::cout << "Dog constructor called\n";
    idea = new (std::nothrow) Brain;
}
Dog::Dog(const Dog& rhs):Animal()
{
    std::cout << "Dog copy constructor called\n";
    type = rhs.type;
    idea = new (std::nothrow) Brain;
};
Dog& Dog::operator=(const Dog& rhs){(void)rhs; std::cout << "Dog assignement operator called\n";return (*this);};
Dog::~Dog()
{
    std::cout << "Dog destructor called\n";
    delete idea;
}
/*-------------------------------------CONSTRUCTOR/DESTRUCTOR-------------------------------------*/
void Dog::makeSound() const {std::cout << "WAOOUFFFF!!!!!!!!\n";}
const std::string& Dog::getType(void) const {return type;};