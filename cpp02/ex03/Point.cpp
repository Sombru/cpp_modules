#include "Point.hpp"

Point::Point(): _x(0), _y(0)
{
	// std::cout << "Point default constructor\n";
}

Point::Point(const float x, const float y): _x(x), _y(y) 
{
	// std::cout << "Point float constructor\n";
}

Point::~Point()
{
	// std::cout << "Point destructor\n";
}

Point::Point(const Point &copy): _x(copy._x), _y(copy._y)
{
	// std::cout << "Point copy constructor\n";
}

Point &Point::operator=(const Point &copy)
{
	(void)copy;
	std::cerr << "Warning: Copy assignment operator called, but Point is immutable. No changes made.\n";
	return *this;
}

const Fixed Point::get_x(void) const
{
	return this->_x;
}

const Fixed Point::get_y(void) const
{
	return this->_y;
}
