#include <iostream>
#include "Timer.h"

size_t calc_exp(size_t num, size_t exp)
{
	if (exp == 1)
	{
		return num;
	}

	return num * calc_exp(num, exp - 1);
}

int main(int argc, char** argv)
{
	Timer t1;
	calc_exp(343, 2411);
	std::cout << t1.elapsed() << std::endl;

	return 0;
}
