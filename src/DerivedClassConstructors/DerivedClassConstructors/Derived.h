#include "Base.h"

#ifndef DERIVED_H
#define DERIVED_H

class Derived : public Base
{
private:
	double m_id{};
public:
	Derived(int, double);
};

#endif
