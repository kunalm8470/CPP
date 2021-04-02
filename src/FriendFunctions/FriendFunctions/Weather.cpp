#include <iostream>
#include "Weather.h"

void print_weather(const Temperature& temp, const Humidity& h)
{
	std::cout << "Today's temperature is= " << temp.m_temp << " celsius, and humidity is= " << h.m_humidity << " %" << std::endl;
}
