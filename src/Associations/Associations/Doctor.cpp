#include <functional>
#include <iostream>
#include <vector>
#include <string>
#include "Doctor.h"
#include "Patient.h"

Doctor::Doctor(const std::string& name, int age) : m_name{ name }, m_age{ age }
{
}

int Doctor::get_age() const
{
	return m_age;
}

const std::string& Doctor::get_name() const
{
	return m_name;
}

void Doctor::add_patient(Patient& p)
{
	m_patients.push_back(p);
}

void Doctor::list_patients()
{
	if (m_patients.empty())
	{
		std::cout << "No patients!" << std::endl;
	}

	std::cout << "-----------------------------" << std::endl;
	std::cout << "Patients under " << m_name << " - " << std::endl;
	int s_no = 1;
	for (const auto& p : m_patients)
	{
		std::cout << s_no << ". " << p.get().get_name() << " aged " << p.get().get_age() << " years old!" << std::endl;
		s_no++;
	}
	std::cout << "-----------------------------" << std::endl;
	std::cout << std::endl;
}

