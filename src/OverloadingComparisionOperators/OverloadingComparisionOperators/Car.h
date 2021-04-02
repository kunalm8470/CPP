#include <string>

#ifndef CAR_H
#define CAR_H

class Car
{
private:
	std::string m_model{};
	std::string m_make{};

public:
	Car(std::string model = "", std::string make = "") : m_model{ model }, m_make{ make }
	{

	}

	std::string get_model() const;
	std::string get_make() const;

	friend bool operator ==(const Car& c1, const Car& c2);
	friend bool operator !=(const Car& c1, const Car& c2);
};

#endif
