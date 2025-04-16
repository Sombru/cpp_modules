#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

class Point
{
private:
	Fixed const _x;
	Fixed const _y;

public:
	Point();
	Point(const float x, const float y);
	Point(const Point &copy);
	Point &operator=(const Point &copy);
	~Point();

	const Fixed get_x() const;
	const Fixed get_y() const;

};



#endif
