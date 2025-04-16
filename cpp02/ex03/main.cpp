#include <iostream>
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main()
{
    Point a(0, 0);
    Point b(10, 5);
    Point c(0, 10);

    Point inside(5, 4);
    Point outside(20, 20);

    std::cout << "Inside: " << bsp(a, b, c, inside) << '\n';   // (true)
    std::cout << "Outside: " << bsp(a, b, c, outside) << '\n'; // (false)

    return 0;
}