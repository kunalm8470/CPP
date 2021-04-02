#ifndef HEADER_H
#define HEADER_H

/*
	C++ only supports rightmost
	default parameters

	This is invalid -
	void print_values(int y = 10, int x);

	Best practice is to declare the
	default argument in the forward
	reference and not in the function definition
*/
void print_values(int x, int y = 10);

/*
	Another way of writing the same thing
*/
void foo(int, int = 4, int = 5);

namespace bar
{
	void baz(float b, float c = 4.1);
}

void baz(float b, float c = 3.997);

/*
	Example of ambiguous function
	declaration

	void print(std::string string = "");
	void print(char ch = ' ');
*/
#endif
