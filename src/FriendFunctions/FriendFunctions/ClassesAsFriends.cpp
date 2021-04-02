#include "ClassesAsFriends.h"

void Class2::mutate_Class1(Class1& c1, int x) const
{
	c1.m_x = x;
}
