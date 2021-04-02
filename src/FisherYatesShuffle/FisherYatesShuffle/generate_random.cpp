#include "generate_random.h"
#include <random>

int generate_random(int low_range, int high_range)
{
	std::random_device rd;
	std::mt19937 mt(rd());

	std::uniform_int_distribution<int> dist(low_range, high_range);
	return dist(mt);
}
