#include "Cents.h"

int Cents::get_cents() const
{
	return m_cents;
}

/*
	Overloading the + operator
	to return a new object of type
	Cents
*/
Cents operator+(const Cents& c1, const Cents& c2)
{
	return Cents(c1.m_cents + c2.m_cents);
}

Cents operator-(const Cents& c1, const Cents& c2)
{
	if (c1.m_cents < c2.m_cents) 
	{
		return Cents(c2.m_cents - c1.m_cents);
	}
	else
	{
		return Cents(c1.m_cents - c2.m_cents);
	}
}

/*
	The following is not a member function
	nor a friend function, but a regular function

	We can't directly access m_cents hence using the
	accessor method
*/
Cents operator*(const Cents& c1, const Cents& c2)
{
	/*
		This is an anonymous object
		which holds the result of the resulting
		product of the two cents
	*/
	return { c1.get_cents() * c2.get_cents() };
}
