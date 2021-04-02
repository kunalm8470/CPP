#include <iostream>
#include "Header.h"

int main(int argc, char** argv)
{
	Something::s_x = 4;
	std::cout << "Static member variable= " << Something::s_x << std::endl;

	SomethingElse s1;
	SomethingElse s2;
	SomethingElse s3;

	// Prints 1, 2, 3
	std::cout << "Accessing static member variables= " << s1.get_mx() << ", " << s2.get_mx() << ", " << s3.get_mx() << std::endl;

	std::cout << "Invoking static member function= " << SomethingElse::get_generator() << std::endl;
	return 0;
}
