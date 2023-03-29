#ifndef _FIXED_HPP_
#define _FIXED_HPP_
#include <iostream>
#include <fstream>
#include <cmath>
class Fixed
{
    public:
        Fixed(void);
        Fixed(const Fixed& rhs);
        Fixed(const int _integers);
        Fixed(const float _float);
        
        float toFloat(void) const;
        int toInt(void) const;

        Fixed& operator=(const Fixed& rhs);
        Fixed& operator+(const Fixed& rhs);
        Fixed& operator*(const Fixed& rhs);
        Fixed& operator-(const Fixed& rhs);
        Fixed& operator/(const Fixed& rhs);

        Fixed& operator++();
        Fixed& operator--();
        Fixed operator++(int);
        Fixed operator--(int);
        
        int  getRawBits(void) const;
        void setRawBits(int const raw);

        static const Fixed& max_ref(const Fixed& a, const Fixed& b);
        static Fixed& max_ref(Fixed& a, Fixed& b);
        static const Fixed& lowest_ref(const Fixed& a, const Fixed& b);
        static Fixed& lowest_ref(Fixed& a, Fixed& b);
        ~Fixed();
    private:
        int _fixed_point;
        static const int fractionals_bits = 8;
        static const float epsilon;
};

inline bool operator< (const Fixed& lhs, const Fixed& rhs) { return lhs.getRawBits() < rhs.getRawBits(); }
inline bool operator> (const Fixed& lhs, const Fixed& rhs) { return lhs.getRawBits() > rhs.getRawBits(); }
inline bool operator<=(const Fixed& lhs, const Fixed& rhs) { return !(lhs.getRawBits() > rhs.getRawBits()); }
inline bool operator>=(const Fixed& lhs, const Fixed& rhs) { return !(lhs.getRawBits() < rhs.getRawBits()); }
inline bool operator==(const Fixed& lhs, const Fixed& rhs) { return lhs.getRawBits() == rhs.getRawBits() ;}
inline bool operator!=(const Fixed& lhs, const Fixed& rhs) { return !(lhs.getRawBits() == rhs.getRawBits()); }
#endif