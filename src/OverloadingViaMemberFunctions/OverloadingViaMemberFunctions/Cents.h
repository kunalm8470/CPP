#include <iostream>

#ifndef CENTS_H
#define CENTS_H

class Cents
{
private:
	int m_cents{};
public:
	Cents(int cents = 0) : m_cents{ cents }
	{

	}

	int get_cents() const;
	Cents operator +(int cents_add);
};

#endif
