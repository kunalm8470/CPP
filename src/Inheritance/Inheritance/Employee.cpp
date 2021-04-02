#include <iostream>
#include "Person.h"
#include "Employee.h"

Employee::Employee(long id) : m_id{ id }
{

}

long Employee::get_id() const
{
	return m_id;
}

std::ostream& operator << (std::ostream& out, const Employee& emp)
{
	out << "Employee - " << std::endl;
	out << "Id: " << emp.m_id << std::endl;
	out << "Name: " << emp.get_name() << std::endl;
	out << "Age: " << emp.get_age() << std::endl;
	return out;
}
