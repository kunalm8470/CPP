#include <iostream>

#ifndef SOMECLASS_H
#define SOMECLASS_H

class MyClass
{
private:
	int m_x{};

public:
	/*
		explicit keyword makes sure that
		we pass a parameter of only int type
		if any other type is passed it will throw
		an compile error
	*/
	explicit MyClass(int x) : m_x{ x }
	{
	}

	/*
		Deleting the constructor accepting
		char made sure no implicit conversion
		happens
	*/
	MyClass(char) = delete;

	friend std::ostream& operator <<(std::ostream& out, const MyClass);
};

#endif
