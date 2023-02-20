#include "./includes/Point.hpp"

float area(Point a, Point b, Point c)
{
    float area;

    area = a.getFixedPointValue('x').getRawBits() * ((b.getFixedPointValue('y').getRawBits() - c.getFixedPointValue('y').getRawBits()));
    area += b.getFixedPointValue('x').getRawBits() * ((c.getFixedPointValue('y').getRawBits() - a.getFixedPointValue('y').getRawBits()));
    area += c.getFixedPointValue('x').getRawBits() * ((a.getFixedPointValue('y').getRawBits() - b.getFixedPointValue('y').getRawBits()));
    area /= 2.0;
    return (area > 0 ? area : -area);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    float full_triangle = area(a, b, c);
    float area_sub_triangle_one = area(point, b, c);
    float area_sub_triangle_two = area(a, point, c);
    float area_sub_triangle_three = area(a, b, point);
    float sum_sub_triangle_area = area_sub_triangle_one + area_sub_triangle_two + area_sub_triangle_three;
    return (full_triangle == sum_sub_triangle_area);
}