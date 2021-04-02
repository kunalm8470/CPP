#ifndef HEADER_H
#define HEADER_H

/*
	Static member variables and
	member functions have internal linkage,
	i.e they are only available in the file (Translation Unit)
	they are declared in

	Static member variables don't need an object
	to access them, they can be accessed on the class
	via the scope resolution operator ::

	Static member variables and functions are shared
	by all the objects of the class

	Static member variables are declared
	in class-scope and definition is done at
	file scope

	But accessibility is the same as class
	member variables and member functions
*/
class Something
{
public:
	static int s_x;

	Something()
	{
		s_x++;
	}

	~Something()
	{
		s_x--;
	}
};

class SomethingElse
{
private:
	static int s_generator;
	int m_x{};

public:
	SomethingElse()
	{
		m_x = s_generator++;
	}

	int get_mx() const;
	static int get_generator();
};

#endif
