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

Fixed::Fixed(const int _integers)
{
    std::cout << "Int constructor called"
              << std::endl;
    this -> _fixed_point = (_integers << fractionals_bits);
}

Fixed::Fixed(const float _float)
{
    std::cout << "Float constructor called"
              << std::endl;
    this -> _fixed_point = roundf((_float * ((float)(1 << fractionals_bits))));
}
/*----------------------CONSTRUCTOR/DESTRUCTOR----------------------*/

/*----------------------PUBLIC_MEMBER_FUNC----------------------*/
int Fixed::getRawBits(void) const
{
    return this -> _fixed_point;
}

void Fixed::setRawBits(int const raw)
{
    this -> _fixed_point = raw;
}

int Fixed::toInt(void) const
{
    int _fix_value = this -> _fixed_point >> fractionals_bits;
    return roundf(_fix_value);
}

float Fixed::toFloat(void) const
{
    float _fix_value = ((float)this -> _fixed_point / (float)(1 << fractionals_bits));
    return _fix_value;
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