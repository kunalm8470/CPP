#include <iostream>

#ifndef FRACTION_H
#define FRACTION_H

class Fraction
{
private:
	int m_numerator{};
	int m_denominator{};

public:
	Fraction() = default;
	Fraction(int, int);

	Fraction& operator=(const Fraction& f);
	friend std::ostream& operator <<(std::ostream& out, const Fraction& f);

	Fraction& set_numerator(int);
	Fraction& set_denominator(int);
};
#endif
