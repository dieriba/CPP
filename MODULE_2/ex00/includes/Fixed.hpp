#ifndef _FIXED_HPP_
#define _FIXED_HPP_
#include <iostream>

class Fixed
{
    public:
        Fixed();
        Fixed(const Fixed& rhs);
        Fixed& operator=(const Fixed& rhs);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        ~Fixed();
    private:
        int _fixed_point;
        static const int fractionals_bits;
};


#endif