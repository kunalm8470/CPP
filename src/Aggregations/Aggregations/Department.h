#include <string>
#include "Teacher.h"

#ifndef DEPARTMENT_H
#define DEPARTMENT_H

class Department
{
private:
	std::string m_name{};
	const Teacher& m_faculty;

public:
	Department(const std::string&, const Teacher&);
};

#endif