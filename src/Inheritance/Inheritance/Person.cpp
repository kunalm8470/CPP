#include <string>
#include "Person.h"

Person::Person(const std::string& name, int age) : m_name{ name }, m_age{ age }
{

}

const std::string& Person::get_name() const
{
	return m_name;
}

int Person::get_age() const
{
	return m_age;
}
