#include <iostream>
#include "Fraction.h"

int main(int argc, char** argv)
{
	Fraction f1{ 5, 3 };

	/*
		Copy initialization
	*/
	Fraction f2 = f1;
	Fraction f3 = make_negative_numerator(f2);

	/*
		Since we are passing an anonymous object
		as the initializer to f4, the copy constructor
		won't be called because the inline anonymous object
		the compiler optimizes away resulting in direct initialization 
		calling the constructor Fraction(int, int) for Fraction(Fraction(int, int))

		This is called elision
	*/
	Fraction f4(Fraction(2, 6));

	std::cout << f1;
	std::cout << f2;
	std::cout << f3;
	std::cout << f4;

	return 0;
}
