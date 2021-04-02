#include <iostream>
#include "Point.h"

int main(int argc, char** argv)
{
	Point p1{ 1, 1, 1 };
	Point p2 = (-p1);

	if (!p2)
	{
		std::cout << "Point is at origin!" << std::endl;
	}
	else
	{
		std::cout << "Point is not at origin!" << std::endl;
	}

	return 0;
}
