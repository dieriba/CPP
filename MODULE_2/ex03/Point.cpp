#include "./includes/Point.hpp"

Point::Point():x(0),y(0){};
Point::Point(const float x, const float y):x(x),y(y){};
Point::Point(const Point& to_copy):x(to_copy.x),y(to_copy.y){};
Point::~Point(){};

Point& Point::operator=(const Point& rhs)
{
	if (this == &rhs) return (*this);
	return *this;
}
const Fixed& Point::getFixedPointValue(char point) {return (point == 'x' ? this -> x : this -> y);}