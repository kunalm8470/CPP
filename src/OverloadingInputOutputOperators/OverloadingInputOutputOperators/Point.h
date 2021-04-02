#include <iostream>

#ifndef POINT_H
#define POINT_H

class Point
{
private:
	double m_x{}, m_y{}, m_z{};
public:
	Point(double x = 0.0, double y = 0.0, double z = 0.0)
		: m_x {x},
		m_y{ y },
		m_z{ z }
	{

	}

	friend std::ostream& operator <<(std::ostream& out, const Point& p);
	friend std::istream& operator >>(std::istream& in, Point& p);
};

#endif
