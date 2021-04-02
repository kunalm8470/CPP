#ifndef CENTS_H
#define CENTS_H

class Cents
{
private:
	int m_cents{};
public:
	Cents(int cents) : m_cents{ cents }
	{

	}

	int get_cents() const;
	friend Cents operator+(const Cents& c1, const Cents& c2);
	friend Cents operator-(const Cents& c1, const Cents& c2);
};

Cents operator*(const Cents& c1, const Cents& c2);

#endif
