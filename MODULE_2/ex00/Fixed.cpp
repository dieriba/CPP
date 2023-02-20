#include "./includes/Fixed.hpp"
/*----------------------CONSTRUCTOR/DESTRUCTOR----------------------*/
Fixed::Fixed():_fixed_point(0)
{
    std::cout << "Default constructor called"
              << std::endl;
}

Fixed::Fixed(const Fixed& rhs)
{
    std::cout << "Copy constructor called"
              << std::endl;
    _fixed_point = rhs.getRawBits();
}

Fixed::~Fixed()
{
    std::cout << "Destructor called"
              << std::endl;
}
/*----------------------CONSTRUCTOR/DESTRUCTOR----------------------*/

/*----------------------PUBLIC_MEMBER_FUNC----------------------*/
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called"
              << std::endl;
    return this -> _fixed_point;
}

void Fixed::setRawBits(int const raw)
{
    this -> _fixed_point = raw;
}
/*----------------------PUBLIC_MEMBER_FUNC----------------------*/

/*----------------------OVERLOAD/OPERATOR----------------------*/
Fixed& Fixed::operator=(const Fixed& rhs)
{
    std::cout << "Copy assignement operator called"
              << std::endl;
    if (this == &rhs)
        return (*this);
    this -> _fixed_point = rhs.getRawBits();
    return (*this);
}
/*----------------------OVERLOAD/OPERATOR----------------------*/

const int Fixed::fractionals_bits = 8;