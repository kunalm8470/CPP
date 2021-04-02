#include <iostream>

#ifndef FRACTION_H
#define FRACTION_H

class Fraction
{
public:
	Fraction(int, int);
	Fraction(const Fraction& f);

	friend std::ostream&  operator << (std::ostream& out, const Fraction& f);
	int get_numerator() const;
	int get_denominator() const;
private:
	int m_numerator{};
	int m_denominator{};
};

Fraction make_negative_numerator(const Fraction&);

#endif
