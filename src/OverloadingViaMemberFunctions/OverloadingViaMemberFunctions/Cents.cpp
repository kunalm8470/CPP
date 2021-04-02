#include "Cents.h"

int Cents::get_cents() const
{
	return m_cents;
}

/*
	For operators that modify the l-value
	member functions are preferred else if
	it doesn't mutate then normal or friend functions
	are preferred
*/
Cents Cents::operator +(int cents_add)
{
	return Cents(this->m_cents + cents_add);
}
