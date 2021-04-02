#include "Header.h"

// Defining the static member variable globally
int Something::s_x = 3;
int SomethingElse::s_generator = 0;

int SomethingElse::get_mx() const
{
	return m_x;
}

/*
	Don't mark with static keyword
	Static member functions don't have a
	this pointer and aren't attached to any object
*/
int SomethingElse::get_generator()
{
	return s_generator;
}