#include<string>

#ifndef TEACHER_H
#define TEACHER_H

class Teacher
{
private:
	std::string m_name{};
public:
	Teacher(const std::string&);
	const std::string& get_name() const;
};

#endif
