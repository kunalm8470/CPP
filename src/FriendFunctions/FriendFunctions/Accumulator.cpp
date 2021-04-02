#include "Accumulator.h"

void Accumulator::accumulate(int value)
{
	m_value += value;
}

/*
	Friend functions don't have
	access to the this-pointer and
	its not subject to member access rules.

	Hence we need to pass the reference
	of the object as a parameter
*/
void reset(Accumulator& acc)
{
	acc.m_value = 0;
}
