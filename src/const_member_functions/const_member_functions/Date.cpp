#include <iostream>
#include "Date.h"

int Date::get_year() const
{
	return this->m_year;
}

int Date::get_month() const
{
	return this->m_month;
}

int Date::get_day() const
{
	return this->m_day;
}

/*
	to_string() function expects a
	constant reference of Date

	Non const member functions can't be called
	on const objects and will cause a compile error
*/
void to_string(const Date& d)
{
	std::cout << d.get_day() << "/" << d.get_month() << "/" << d.get_year() << std::endl;
}
