#include <string>
#include "Car.h"

std::string Car::get_model() const
{
	return m_model;
}

std::string Car::get_make() const
{
	return m_make;
}

bool operator == (const Car& c1, const Car& c2)
{
	return c1.m_model == c2.m_model
		&& c1.m_make == c2.m_make;
}

bool operator != (const Car& c1, const Car& c2)
{
	return c1.m_model != c2.m_model
		&& c1.m_make != c2.m_make;
}
