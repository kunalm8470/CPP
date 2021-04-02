#include <iostream>
#include "Point.h"

/*
	std::cout is an object of std::ostream
	We are passing a reference of std::ostream
*/
std::ostream& operator << (std::ostream& out, const Point& p)
{
	out << "(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ")" << std::endl;
	return out;
}

/*
	std::cin is an object of std::istream
	We are passing a reference of std::istream
*/
std::istream& operator >> (std::istream& in, Point& p)
{
	std::cout << "X co-ordinate: ";
	in >> p.m_x;

	std::cout << "Y co-ordinate: ";
	in >> p.m_y;

	std::cout << "Z co-ordinate: ";
	in >> p.m_z;

	return in;
}
