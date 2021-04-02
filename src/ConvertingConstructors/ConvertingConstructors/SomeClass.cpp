#include <iostream>
#include "SomeClass.h"

std::ostream& operator <<(std::ostream& out, const MyClass c)
{
	out << "x= " << c.m_x << std::endl;
	return out;
}
