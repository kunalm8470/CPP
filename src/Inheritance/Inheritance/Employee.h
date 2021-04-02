#include <iostream>
#include "Person.h"

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee: public Person
{
private:
	long m_id{};
public:
	Employee() = default;
	explicit Employee(long);
	long get_id() const;
	friend std::ostream& operator << (std::ostream&, const Employee&);
};

#endif