#include <iostream>
#include <string>
#include "Creature.h"

Creature::Creature(std::string& name, const Point2D& location) : m_name{ name }, m_location{ location }
{
}

std::ostream& operator << (std::ostream& out, const Creature& c)
{
	out << c.m_name << " is at " << "(" << c.m_location.get_x_coord() << ", " << c.m_location.get_y_coord() << ")" << std::endl;
	return out;
}

void Creature::move_to(int x, int y)
{
	m_location.set_point(x, y);
}
