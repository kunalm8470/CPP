#include <iostream>
#include "Header.h"

int Cents::get_cents() const
{
	return m_cents;
}

void print_cents(const Cents& c)
{
	std::cout << "Cents= " << c.m_cents << std::endl;
}
