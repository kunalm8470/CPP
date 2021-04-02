#include <iostream>
#include "Point.h"

std::ostream& operator << (std::ostream& out, const Point& p1)
{
	return out << "(" << p1.m_x << ", " << p1.m_y << ", " << p1.m_z << ")" << std::endl;
}

/*
	Returning the this pointer pointee (by reference) 
	directly in the case of pre-increment and pre-decrement
*/
Point& Point::operator ++()
{
	this->m_x += 1;
	this->m_y += 1;
	this->m_z += 1;

	return *this;
}

Point& Point::operator --()
{
	this->m_x -= 1;
	this->m_y -= 1;
	this->m_z -= 1;

	return *this;
}

/*
	Returning a copy of the object
	simulating the side-effect of the copied
	variable in the case of post-increment and post-decrement

	The dummy parameter is kept to differentiate between
	pre and post increment/decrement by the compiler using
	function overloading, and the type of this dummy parameter should
	always be int, else it won't compile
*/
Point Point::operator ++(int)
{
	Point temp{ this->m_x, this->m_y, this->m_z };
	this->m_x += 1;
	this->m_y += 1;
	this->m_z += 1;
	return temp;
}

Point Point::operator --(int)
{
	Point temp{ this->m_x, this->m_y, this->m_z };
	this->m_x -= 1;
	this->m_y -= 1;
	this->m_z -= 1;
	return temp;
}
