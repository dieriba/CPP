#include "./includes/Dog.hpp"


Dog::Dog():type("dog")
{std::cout << "Dog constructor called\n";}
Dog::~Dog(){std::cout << "Dog destructor called\n";}
void Dog::makeSound() const {std::cout << "WAOOUFFFF!!!!!!!!\n";}
const std::string& Dog::getType(void) const {return type;};