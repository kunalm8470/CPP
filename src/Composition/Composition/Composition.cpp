#include <iostream>
#include <string>
#include "Point2D.h"
#include "Creature.h"

int main(int argc, char** argv)
{
	std::string name;
	int x, y;

	std::cout << "what do you want to name your creature: " << std::endl;
	std::cin >> name;

	Creature c{ name, { 0, 0 } };

	while (true)
	{
		std::cout << c;
		std::cout << "Enter new x-location for " << name << " and -1 to quit" << std::endl;
		std::cin >> x;
		if (x == -1)
		{
			break;
		}

		std::cout << "Enter new y-location for " << name << " and -1 to quit" << std::endl;
		std::cin >> y;
		if (y == -1)
		{
			break;
		}

		c.move_to(x, y);
	}

	return 0;
}
