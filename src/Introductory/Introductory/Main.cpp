#include <iostream>
#include <iomanip>

struct Employee
{
	short id;
	int age;
	double wage;
};

struct Company
{
	Employee CEO; // Employee is a struct within the Company struct
	int numberOfEmployees;
};

// Enum types (Unscoped ones)
enum Color
{
	RED, // RED is placed in the same scope as Color
	BLUE
};

enum Fruit
{
	BANANA, // BANANA is placed in the same scope as Fruit
	APPLE
};

struct Point3d
{
	double x;
	double y;
	double z;
};

Point3d getZeroPoint()
{
	// We can create a variable and return the variable.
	Point3d temp{ 0.0, 0.0, 0.0 };
	return temp;
}

Point3d getZeroPoint2()
{
	// We can return directly. We already specified the type
	// at the function declaration (Point3d), so we don't need
	// it again here.
	return { 0.0, 0.0, 0.0 };
}

Point3d getZeroPoint3()
{
	// We can use empty curly braces to zero-initialize all
	// members of `Point3d`.
	return {};
}

int main(char** argv, int argc) {
	int variable = 8;
	unsigned int unsigned_variable = 4;
	char c = 'f';
	char cc = 50;
	short s = 127;
	long l = 2;
	long long ll = 444;
	float f{ 123456789.0f }; // f has 10 significant digits
	double d = 1.4;
	bool b = true; // 1 byte (Has 0 or 1 value)

	std::cout << std::setprecision(9); // to show 9 digits in f
	std::cout << f << '\n';

	// Printing sizes of data-types
	std::cout << "Int: " << sizeof(int) << std::endl;
	std::cout << "Char: " << sizeof(char) << std::endl;
	std::cout << "Short: " << sizeof(short) << std::endl;
	std::cout << "Long: " << sizeof(long) << std::endl;
	std::cout << "Long Long: " << sizeof(long long) << std::endl;
	std::cout << "Float: " << sizeof(float) << std::endl;
	std::cout << "Double: " << sizeof(double) << std::endl;
	std::cout << "Bool: " << sizeof(bool) << std::endl;

	double zero { 0.0 };
	double posinf { 5.0 / zero }; // positive infinity
	std::cout << posinf << std::endl;

	double neginf { -5.0 / zero }; // negative infinity
	std::cout << neginf << std::endl;

	double nan { zero / zero }; // not a number (mathematically invalid)
	std::cout << nan << std::endl;

	double pi { 3.14159 }; // 3.14159 is a double literal in standard notation
	double avogadro { 6.02e23 }; // 6.02 x 10^23 is a double literal in scientific notation

	// C++ 14 and up only
	int bin{};
	bin = 0x01; // assign binary 0000 0001 to the variable
	bin = 0b1;  // assign binary 0000 0001 to the variable

	Color color = RED; // Color and RED can be accessed in the same scope (no prefix needed)
	Fruit fruit = BANANA; // Fruit and BANANA can be accessed in the same scope (no prefix needed)

	if (color == fruit) // The compiler will compare a and b as integers
		std::cout << "color and fruit are equal\n"; // and find they are equal!
	else
		std::cout << "color and fruit are not equal\n";

	// Scoped enumerations (class based) C++11 and above
	enum class DAY_OF_WEEK
	{
		MONDAY,
		TUESDAY,
		WEDNESDAY,
		THURSDAY,
		FRIDAY,
		SATURDAY,
		SUNDAY
	};

	DAY_OF_WEEK saturday = DAY_OF_WEEK::SATURDAY;

	std::cout << static_cast<int>(saturday);

	// Structures
	Employee kunal;
	kunal.age = 25;
	kunal.id = 2618;
	kunal.wage = 1000;

	// Structure initializer list
	Employee joe{ 21, 1234, 15000 };

	// Declare a structure from another structure
	Point3d zeroStruct { getZeroPoint2() };

	// Nested structures
	Company test{ joe, 1000 };

	unsigned short x{ 65535 }; // largest 16-bit unsigned value possible
	std::cout << "x was: " << x << '\n';

	x = 65536; // 65536 is out of our range, so we get wrap-around
	std::cout << "x is now: " << x << '\n';

	x = 65537; // 65537 is out of our range, so we get wrap-around
	std::cout << "x is now: " << x << '\n';

	unsigned short x1{ 0 }; // smallest 2-byte unsigned value possible
	std::cout << "x1 was: " << x1 << '\n';

	x1 = -1; // -1 is out of our range, so we get wrap-around
	std::cout << "x1 is now: " << x1 << '\n';

	x1 = -2; // -2 is out of our range, so we get wrap-around
	std::cout << "x1 is now: " << x1 << '\n';

	unsigned int i1{ 3 };
	unsigned int i2{ 5 };

	// The unsigned int difference will cause -2 to be subtracted from the max 4-byte integer giving 4294967294
	std::cout << i1 - i2 << '\n';

	return 0;
}