#include <iostream>
#include "Fraction.h"

Fraction::Fraction(int numerator, int denominator) : m_numerator{ numerator }, m_denominator{ denominator }
{
}

/*
	In C++ self-assignment is possible
	hence for detecting that and preventing
	it, we need a guard condition
*/
Fraction& Fraction::operator=(const Fraction& f)
{
	// self-assignment guard
	if (this == &f)
		return *this;

	m_numerator = f.m_numerator;
	m_denominator = f.m_denominator;

	return *(this);
}

std::ostream& operator <<(std::ostream& out, const Fraction& f)
{
	out << "(" << f.m_numerator << "/" << f.m_denominator << ")" << std::endl;
	return out;
}

Fraction& Fraction::set_numerator(int numerator)
{
	m_numerator = numerator;
	return *(this);
}

Fraction& Fraction::set_denominator(int denominator)
{
	m_denominator = denominator;
	return *(this);
}
