#include <cassert>
#include <cstring>
#include "MyString.h"

MyString::MyString(const char* source = "")
{
	// make sure source isn't a null string
	assert(source); 

	// Find the length of the string
	// Plus one character for a terminator
	m_length = std::strlen(source) + 1;

	// Allocate a buffer equal to this length
	m_data = new char[m_length];

	// Copy the parameter string into our internal buffer
	for (int i{ 0 }; i < m_length; ++i)
		m_data[i] = source[i];

	// Make sure the string is terminated
	m_data[m_length - 1] = '\0';
}

MyString::MyString(const MyString& src)
{
	if (this != &src)
	{
		deep_copy(src);
	}
}

MyString::~MyString()
{
	delete[] m_data;
}

void MyString::deep_copy(const MyString& src)
{
	// Assertion for null string
	assert(src.m_data);

	/*
		Delete if already present
		to avoid memory leaks
	*/
	delete[] m_data;

	m_length = src.m_length;

	if (src.m_data)
	{
		m_data = new char[m_length];
		for (int i = 0; i < m_length; ++i)
		{
			m_data[i] = src.m_data[i];
		}
	}
	else
	{
		m_data = nullptr;
	}
}

char* MyString::get_data() const
{
	return m_data;
}

int MyString::get_length() const
{
	return m_length;
}

MyString& MyString::operator=(const MyString& m)
{
	if (this == &m)
	{
		deep_copy(m);
	}

	return *(this);
}
