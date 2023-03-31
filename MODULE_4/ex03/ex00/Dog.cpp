#include "./includes/Dog.hpp"

/*-------------------------------------------CONSTRUCTOR/DESTRUCTOR-------------------------------------------*/
Dog::Dog():type("Dog"){std::cout << "Dog constructor called\n";}
Dog::Dog(const Dog& rhs):type(rhs.getType()){};
Dog& Dog::operator=(const Dog& rhs)
{
    type = rhs.getType();
    return *this;
};
Dog::~Dog(){std::cout << "Dog destructor called\n";}
/*-------------------------------------------CONSTRUCTOR/DESTRUCTOR-------------------------------------------*/
void Dog::makeSound() const {std::cout << "WAOOUFFFF!!!!!!!!\n";}
const std::string& Dog::getType(void) const {return type;};