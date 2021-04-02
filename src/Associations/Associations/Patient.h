#include <functional>
#include <string>
#include <vector>

#ifndef PATIENT_H
#define PATIENT_H

class Doctor;

class Patient
{
private:
	std::string m_name{};
	int m_age{};
	std::vector<std::reference_wrapper<Doctor>> m_doctors;

public:
	Patient(const std::string&, int);
	int get_age() const;
	const std::string& get_name() const;
	void add_doctor(Doctor&);
	void list_doctors();
};

#endif
