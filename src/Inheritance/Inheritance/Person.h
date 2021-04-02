#include <string>

#ifndef PERSON_H
#define PERSON_H

class Person
{
public:
	std::string m_name{};
	int m_age{};

	Person() = default;
	Person(const std::string&, int);
	const std::string& get_name() const;
	int get_age() const;
};

#endif
