#include "./includes/WrongCat.hpp"

/*-------------------------------------------CONSTRUCTOR/DESTRUCTOR-------------------------------------------*/
WrongCat::WrongCat():type("WrongCat"){std::cout << "WrongCat constructor called\n";}
WrongCat::WrongCat(const WrongCat& rhs):type(rhs.getType()){};
WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
    type = rhs.getType();
    return *this;
};
WrongCat::~WrongCat(){std::cout << "WrongCat destructor called\n";}
/*-------------------------------------------CONSTRUCTOR/DESTRUCTOR-------------------------------------------*/
void WrongCat::makeSound() const {std::cout << "WAOUFFFFF!!!!!!!!\n";}
const std::string& WrongCat::getType(void) const {return type;};