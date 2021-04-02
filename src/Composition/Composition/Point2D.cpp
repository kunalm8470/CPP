#include "Point2D.h"

Point2D::Point2D(int x, int y) : m_x{ x }, m_y{ y }
{
}

void Point2D::set_point(int x, int y)
{
	m_x = x;
	m_y = y;
}

int Point2D::get_x_coord() const
{
	return m_x;
}

int Point2D::get_y_coord() const
{
	return m_y;
}
