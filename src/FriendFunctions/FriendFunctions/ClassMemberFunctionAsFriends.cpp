#include <iostream>
#include "ClassMemberFunctionAsFriends.h"

void A::func1(const B& b)
{
	std::cout << "Private member of b= " << b.m_b << std::endl;
}
