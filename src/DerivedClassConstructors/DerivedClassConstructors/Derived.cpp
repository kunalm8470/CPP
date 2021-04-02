#include <iostream>
#include "Base.h"
#include "Derived.h"

Derived::Derived(int id, double d_id) : Base{ id }, m_id{ d_id }
{
	std::cout << "Derived class constructor called!" << std::endl;
}
