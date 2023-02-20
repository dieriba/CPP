#ifndef __POINT_HPP__
#define __POINT_HPP__
#include "Fixed.hpp"

class Point
{
    public:
        Point();
        Point(const float x, const float y);
        Point(const Point& to_copy);
        ~Point();
        
        const Fixed& getFixedPointValue(char point);
        Point& operator=(const Point& rhs);
    private:
        const Fixed x;
        const Fixed y;
};
bool bsp( Point const a, Point const b, Point const c, Point const point);
#endif