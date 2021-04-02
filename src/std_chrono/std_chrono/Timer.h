#include<chrono>
#ifndef TIMER_H
#define TIMER_H

class Timer
{
private:
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1>>;
	std::chrono::time_point<clock_t> m_begin;

public:
	Timer() : m_begin{ clock_t::now() }
	{

	}

	void reset();
	double elapsed() const;
};

#endif
