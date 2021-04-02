#include "Teacher.h"
#include "Department.h"

Department::Department(const std::string& name, const Teacher& faculty) : m_name{ name }, m_faculty{ faculty }
{
}