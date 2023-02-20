#ifndef _FIXED_HPP_
#define _FIXED_HPP_
#include <iostream>
#include <fstream>
#include <cmath>
class Fixed
{
    public:
        Fixed();
        Fixed(const Fixed& rhs);
        Fixed(const int _integers);
        Fixed(const float _float);
        float toFloat(void) const;
        int toInt(void) const;
        Fixed& operator=(const Fixed& rhs);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        ~Fixed();
    private:
        int _fixed_point;
        static const int fractionals_bits = 8;
};
#endif