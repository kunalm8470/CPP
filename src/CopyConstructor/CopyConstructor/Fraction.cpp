#include <cassert>
#include <iostream>
#include "Fraction.h"

Fraction::Fraction(int numerator = 0, int denominator = 1)
	: m_numerator{ numerator },
	m_denominator{ denominator }
{
	assert(m_denominator != 0);
}

/*
	Copy constructors are created implicitly
	with public access by the compiler 
	like the default constructor,

	by default the implicitly created
	copy constructor uses member-wise initialization,

	but there might be scenarios where we need explicit logic
	to be performed for complex data members, in those cases an
	explicit copy constructor might prove useful

	The below is a explicitly written copy constructor

	Pre C++11 to make a class not generate copy constructor
	we used to mark it private

	From C++11 we can use the delete keyword, like -
	Fraction(const Fraction& f) = delete;
*/
Fraction::Fraction(const Fraction& f)
	: m_numerator{ f.m_numerator },
	m_denominator{ f.m_denominator }
{
	std::cout << "Copy constructor called!" << std::endl;
	assert(m_denominator != 0);
}


std::ostream& operator << (std::ostream& out, const Fraction& f)
{
	out << "(" << f.m_numerator << "/" << f.m_denominator << ")" << std::endl;
	return out;
}

int Fraction::get_numerator() const
{
	return m_numerator;
}

int Fraction::get_denominator() const
{
	return m_denominator;
}

Fraction make_negative_numerator(const Fraction& f)
{
	return Fraction((-f.get_numerator()), f.get_denominator());
}
