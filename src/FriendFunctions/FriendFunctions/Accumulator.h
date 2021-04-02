#include <iostream>
#ifndef ACCUMULATOR_H
#define ACCUMULATOR_H

class Accumulator
{
private:
	int m_value{};
public:
	void accumulate(int value);
	friend void reset(Accumulator& acc);

	friend void print_accumulated(const Accumulator& acc)
	{
		std::cout << "Inline friend function= " << acc.m_value << std::endl;
	}
};

#endif