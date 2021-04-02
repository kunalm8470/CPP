#include <iostream>
#include "Base.h"

Base::Base(int id = 0) : i_id{ id }
{
	std::cout << "Base constructor called!" << std::endl;
}
