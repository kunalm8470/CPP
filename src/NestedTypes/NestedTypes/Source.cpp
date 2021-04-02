#include <iostream>
#include <string>
#include "Header.h"

/*
	Use scope-resolution operator
	twice to provide the definition
	of the inner struct
*/
void Outer::Inner::display_something()
{
	std::cout << "From inner struct!" << std::endl;
}

void Fruit::print_fruit_type()
{
	std::string fruit_type;
	switch (m_type)
	{
		case Fruit::FruitType::APPLE:
			fruit_type = "Apple";
			break;
		case Fruit::FruitType::BANANA:
			fruit_type = "BANANA";
			break;
		case Fruit::FruitType::CHERRY:
			fruit_type = "CHERRY";
			break;
		default:
			fruit_type = "Invalid type!";
			break;
	}
	std::cout << fruit_type << std::endl;
}
