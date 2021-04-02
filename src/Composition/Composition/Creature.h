#include <iostream>
#include <string>
#include "Point2D.h"

#ifndef CREATURE_H
#define CREATURE_H

class Creature
{
private:
	std::string m_name{};
	Point2D m_location;
public:
	Creature(std::string&, const Point2D&);
	friend std::ostream& operator<<(std::ostream&, const Creature&);
	void move_to(int, int);
};

#endif
