#include "./includes/Fixed.hpp"
#include "./includes/Point.hpp"
std::ostream& operator <<(std::ostream& output, const Fixed& fixed)
{
   output << fixed.toFloat();
   return output;
}

void is_point_in(bool in, Point p)
{
   std::cout << "Point p locate at: x "
             << p.getFixedPointValue('x')
             << " and locate at: y " << p.getFixedPointValue('y')
             << " is " << (in ? "in " : " not in ") << "the triangle."
             << std::endl;
}

int main( void ) 
{

   Point	a(10, 0);
	Point	b(20, 0);
	Point	c(5, 15);
	Point	p1(0, 0);
	Point	p2(10.6, 2);
	Point	p3(8, 4);
	Point	p4(3.25, 3.13);
	Point	p5(4.75, 5.25);
	Point	p6(5, 7);
   is_point_in(bsp(a, b, c, p1), p1);
   is_point_in(bsp(a, b, c, p2), p2);
   is_point_in(bsp(a, b, c, p3), p3);
   is_point_in(bsp(a, b, c, p4), p4);
   is_point_in(bsp(a, b, c, p5), p5);
   is_point_in(bsp(a, b, c, p6), p6);
   return 0;
}