#include "Point.hpp"

Fixed calculateArea(const Point &p1, const Point &p2, const Point &p3)
{
    Fixed area = (p1.get_x() * (p2.get_y() - p3.get_y()) +
                  p2.get_x() * (p3.get_y() - p1.get_y()) +
                  p3.get_x() * (p1.get_y() - p2.get_y())) / 2;

	if (area < 0)
		return area * -1;
	else
		return area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed totalArea = calculateArea(a, b, c); // the area of triangle

    Fixed area1 = calculateArea(point, b, c); // calculating helper triangles
    Fixed area2 = calculateArea(point, a, c); // calculating helper triangles
    Fixed area3 = calculateArea(point, a, b); // calculating helper triangles

// if sum of helper triangles areas are equal to sum of total area POINT must be inside it 
    if (area1 + area2 + area3 == totalArea)
	    return true;

    return false;
}