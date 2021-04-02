#include <string>
#include "Teacher.h"

Teacher::Teacher(const std::string& name) : m_name{ name }
{
}

const std::string& Teacher::get_name() const
{
	return m_name;
}
