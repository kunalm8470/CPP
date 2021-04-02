#include <functional>
#include <iostream>
#include <vector>
#include <string>
#include "Doctor.h"
#include "Patient.h"

Patient::Patient(const std::string& name, int age) : m_name{ name }, m_age{ age }
{

}

int Patient::get_age() const
{
	return m_age;
}

const std::string& Patient::get_name() const
{
	return m_name;
}

void Patient::add_doctor(Doctor& d)
{
	m_doctors.push_back(d);
}

void Patient::list_doctors()
{
	if (m_doctors.empty())
	{
		std::cout << m_name << " is healthy!" << std::endl;
	}

	std::cout << "-----------------------------" << std::endl;
	std::cout << m_name << " consults doctors - " << std::endl;
	int s_no = 1;
	for (const auto& d : m_doctors)
	{
		std::cout << s_no << ". " << d.get().get_name() << std::endl;
	}
	std::cout << "-----------------------------" << std::endl;
	std::cout << std::endl;
}
