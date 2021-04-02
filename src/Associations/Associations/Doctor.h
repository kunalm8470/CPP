#include <functional>
#include <string>
#include <vector>

#ifndef DOCTOR_H
#define DOCTOR_H

/*
	Forward declare patient class
*/
class Patient;

class Doctor
{
private:
	int m_age{};
	std::string m_name{};
	std::vector<std::reference_wrapper<Patient>> m_patients{};

public:
	Doctor(const std::string& , int);
	const std::string& get_name() const;
	int get_age() const;
	void add_patient(Patient&);
	void list_patients();
};

#endif
