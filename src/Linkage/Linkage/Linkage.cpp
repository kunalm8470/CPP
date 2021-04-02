#include <iostream>
#include "Header.h"
#include "Constants.h"

/*
	Local to this translation unit

	No relation to foo in linkage.cpp

	Global and static variables
	have static duration, i.e
	they are created at program start
	and destroyed at program end

	Local variables and function parameters
	have automatic duration

	Variables allocated dynamically using new
	operator have dynamic duration, as they are
	destroyed dynamically by delete operator
	based on the programmer's wish
*/
static int foo = -42;

/*
	Global variables, enums,
	structures and classes 
	declared in global scope
	have global scope and can be accessed
	anywhere in the file

	Variables and function parameters
	have block scope
*/
/*
	Local variables and function parameters 
	have no linkage

	Static variables and functions, const global
	variables, Functions in anonymous namespace
	enums and classes have internal linkage,
	i.e they can be accessed anywhere in the same
	file or accessible in the same translation unit

	Functions, non-const global variables, extern
	const variables, inline const variables, enums and
	classes defined in some namespace have external linkage,
	i.e they can be accessed in other files using forward declaration (header files)
*/
int global_variable = 4;

/*
	variable foo has
	internal linkage in both
	foo1() and foo2()
*/
int foo1() 
{ 
	static int foo = 42; 
	foo++; 
	return foo; 
}

int foo2() 
{
	static int foo = -43; 
	foo++; 
	return foo; 
}

int main(int argc, char** argv)
{
    std::cout << "Global variable defined in other file with external linkage= " << global_var << std::endl;

	std::cout << "foo1= " << foo1() << std::endl;
	std::cout << "foo2= " << foo2() << std::endl;

	Color t = Color::BLUE;
	std::cout << "Enum color (external linkage) accessed in other file by forward declaration= " << static_cast<unsigned int>(t) << std::endl;

	std::cout << "Storing global constants in a header file with header guards and inline constexpr (Compile time constant)= " << constants::gravity_speed << std::endl;
    return 0;
}
