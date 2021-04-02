#include <iostream>
#ifndef ANONYMOUSOBJECTS_H
#define ANONYMOUSOBJECTS_H

class Cents
{
private:
	int m_cents;
public:
	Cents(int cents) : m_cents{ cents }
	{

	}

	int get_cents() const;
	friend void print_cents(const Cents& c);

	~Cents()
	{
		std::cout << "Destroying cents!" << std::endl;
	}
};

#endif
