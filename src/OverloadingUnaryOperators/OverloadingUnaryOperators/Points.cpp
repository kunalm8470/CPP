#include "Point.h"

Point Point::operator-()
{
	return Point(this->m_x - 1, this->m_y - 1, this->m_z - 1);
}

bool Point::operator!()
{
	return this->m_x == 0.0
		&& this->m_y == 0.0
		&& this->m_z == 0.0;
}
