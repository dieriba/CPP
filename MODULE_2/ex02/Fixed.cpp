#include "./includes/Fixed.hpp"
/*----------------------CONSTRUCTOR/DESTRUCTOR----------------------*/
Fixed::Fixed(void):_fixed_point(0){};
Fixed::Fixed(Fixed const &rhs):_fixed_point(rhs.getRawBits()) {};
Fixed::Fixed(const int _integers):_fixed_point(_integers << fractionals_bits) {};
Fixed::Fixed(const float _float):_fixed_point(roundf(_float * ((float)(1 << fractionals_bits)))){};
Fixed::~Fixed(){};
/*----------------------CONSTRUCTOR/DESTRUCTOR----------------------*/

/*----------------------PUBLIC_MEMBER_FUNC----------------------*/
int Fixed::getRawBits(void) const {return _fixed_point;}
void Fixed::setRawBits(int const raw){_fixed_point = raw;}
int Fixed::toInt(void) const {return roundf(_fixed_point >> fractionals_bits);}
float Fixed::toFloat(void) const {return ((float)_fixed_point / (float)(1 << fractionals_bits));}
/*----------------------PUBLIC_MEMBER_FUNC----------------------*/

/*----------------------OVERLOAD/OPERATOR----------------------*/
Fixed& Fixed::operator=(const Fixed& rhs)
{
    if (this != &rhs)
        _fixed_point = rhs.getRawBits();
    return (*this);
}

Fixed& Fixed::operator+(const Fixed& rhs)
{
    _fixed_point += rhs.getRawBits();
    return (*this);
}

Fixed& Fixed::operator-(const Fixed& rhs)
{
    _fixed_point -= rhs.getRawBits();
    return (*this);
}

Fixed& Fixed::operator*(const Fixed& rhs)
{
    _fixed_point = (_fixed_point * rhs.getRawBits()) >> fractionals_bits;
    return (*this);
}

Fixed& Fixed::operator/(const Fixed& rhs)
{
    _fixed_point =  (_fixed_point << fractionals_bits) / rhs.getRawBits();
    return (*this);
}

Fixed Fixed::operator++ (int)
{
    Fixed tmp(*this);

    _fixed_point++;
    return tmp;
}

Fixed Fixed::operator-- (int)
{
    Fixed tmp(*this);

    _fixed_point--;
    return tmp;
}

Fixed& Fixed::operator++()
{
    _fixed_point++;
    return *this;
}

Fixed& Fixed::operator--()
{
    _fixed_point--;
    return *this;
}
/*----------------------OVERLOAD/OPERATOR----------------------*/

/*----------------------SHARED MENBER----------------------*/
const Fixed& Fixed::max_ref(const Fixed& a, const Fixed& b){return (a < b ? b : a);}
const Fixed& Fixed::lowest_ref(const Fixed& a, const Fixed& b){return (a > b ? b : a);}
Fixed& Fixed::max_ref(Fixed& a, Fixed& b){return (a < b ? b : a);}
Fixed& Fixed::lowest_ref(Fixed& a, Fixed& b){return (a > b ? b : a);}
/*----------------------SHARED MENBER----------------------*/
const float Fixed::epsilon = 1 / (float)(1 << 8);