#include "./includes/Fixed.hpp"
/*----------------------CONSTRUCTOR/DESTRUCTOR----------------------*/
Fixed::Fixed(void):_fixed_point(0){};
Fixed::Fixed(Fixed const &rhs):_fixed_point(rhs.getRawBits()) {};
Fixed::Fixed(const int _integers):_fixed_point(_integers << fractionals_bits) {};
Fixed::Fixed(const float _float):_fixed_point(roundf(_float * ((float)(1 << fractionals_bits)))){};
Fixed::~Fixed(){};
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
    float _fix_value = (this -> _fixed_point / (float)(1 << fractionals_bits));
    return _fix_value;
}
/*----------------------PUBLIC_MEMBER_FUNC----------------------*/

/*----------------------OVERLOAD/OPERATOR----------------------*/
Fixed& Fixed::operator=(const Fixed& rhs)
{
    if (this != &rhs)
        this -> _fixed_point = rhs.getRawBits();
    return (*this);
}

Fixed& Fixed::operator+(const Fixed& rhs)
{
    this -> _fixed_point += rhs.getRawBits();
    return (*this);
}

Fixed& Fixed::operator-(const Fixed& rhs)
{
    this -> _fixed_point -= rhs.getRawBits();
    return (*this);
}

Fixed& Fixed::operator*(const Fixed& rhs)
{
    this -> _fixed_point = this -> _fixed_point * rhs.getRawBits();
    this -> _fixed_point >>=fractionals_bits;
    return (*this);
}

Fixed& Fixed::operator/(const Fixed& rhs)
{
    this -> _fixed_point =  (this -> _fixed_point << fractionals_bits) / rhs.getRawBits();
    return (*this);
}

Fixed Fixed::operator++ (int)
{
    Fixed tmp;

    tmp = *this;
    this -> _fixed_point += epsilon;
    return tmp;
}

Fixed Fixed::operator-- (int)
{
    Fixed tmp;

    tmp = *this;
    this -> _fixed_point -= epsilon;
    return tmp;
}

Fixed& Fixed::operator++()
{
    this -> _fixed_point += epsilon;
    return *this;
}

Fixed& Fixed::operator--()
{
    this -> _fixed_point -= epsilon;
    return *this;
}
/*----------------------OVERLOAD/OPERATOR----------------------*/

/*----------------------SHARED MENBER----------------------*/
const Fixed& Fixed::max_ref(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return b;
    return a;
}

Fixed& Fixed::max_ref(Fixed& a, Fixed& b)
{
     if (a < b)
        return b;
    return a;
}

const Fixed& Fixed::lowest_ref(const Fixed& a, const Fixed& b)
{
     if (a > b)
        return b;
    return a;
}

Fixed& Fixed::lowest_ref(Fixed& a, Fixed& b)
{
    if (a > b)
        return b;
    return a;
}
/*----------------------SHARED MENBER----------------------*/
static const float epsilon = 1 / (float)(1 << 8);