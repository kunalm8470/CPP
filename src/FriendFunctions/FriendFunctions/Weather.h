#ifndef WEATHER_H
#define WEATHER_H

class Humidity;

class Temperature
{
private:
	int m_temp;
public:
	Temperature(int temp = 0) : m_temp{ temp }
	{

	}

	friend void print_weather(const Temperature& temp, const Humidity& h);
};

class Humidity
{
private:
	int m_humidity;
public:
	Humidity(int humidity = 0) : m_humidity{ humidity }
	{

	}

	friend void print_weather(const Temperature& temp, const Humidity& h);
};

#endif
