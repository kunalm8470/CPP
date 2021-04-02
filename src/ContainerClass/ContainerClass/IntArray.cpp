#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <iostream>
#include "IntArray.h"

IntArray::IntArray(std::initializer_list<int> list) : IntArray(static_cast<int>(list.size()))
{
	m_length = 0;
	for (int element : list)
	{
		m_data[m_length++] = element;
	}
}

IntArray::IntArray(int size) : m_data{ new int[size] }, m_length{ size }
{

}

IntArray::~IntArray()
{
	delete[] m_data;
	m_data = nullptr;
	m_length = 0;
}

std::ostream& operator << (std::ostream& out, const IntArray& iArr)
{
	out << "Length is now: " << iArr.m_length << " elements!" << std::endl;
	std::cout << "Elements are: " << std::endl;
	for (int i = 0; i < iArr.m_length; ++i)
	{
		out << *(iArr.m_data + i) << " ";
	}
	std::cout << std::endl;
	return out;
}

int& IntArray::operator[](int index)
{
	assert(index >= 0 && index < m_length);
	return m_data[index];
}

const int& IntArray::operator[](int index) const
{
	assert(index >= 0 && index < m_length);
	return m_data[index];
}

void IntArray::erase()
{
	delete[] m_data;
	m_data = nullptr;
	m_length = 0;
}

void IntArray::resize(int size)
{
	assert(size >= 0);

	if (size == 0)
	{
		erase();
		return;
	}

	if (size == m_length) 
	{
		return;
	}

	int* data = new int[size] {};
	int resize_length = (size > m_length) ? m_length : size;
	for (int i = 0; i < resize_length; ++i)
	{
		data[i] = m_data[i];
	}

	delete[] m_data;

	m_data = new int[size];
	std::copy(data, data + size, m_data);
	m_length = size;
	delete[] data;
}

void IntArray::insert_at(int value, const int index)
{
	assert(index >= 0 && index <= m_length);
	
	const int new_length = m_length + 1;
	int* data = new int[new_length]{};
	for (int i = 0; i < index; ++i)
	{
		data[i] = m_data[i];
	}

	data[index] = value;

	for (int i = index; i < m_length; ++i)
	{
		data[i + 1] = m_data[i];
	}
	
	delete[] m_data;

	m_data = new int[new_length];
	std::copy(data, data + new_length, m_data);
	m_length = new_length;

	delete[] data;
}

void IntArray::insert_front(int value)
{
	insert_at(value, 0);
}

void IntArray::insert_rear(int value)
{
	insert_at(value, m_length);
}

void IntArray::insert(int value, int index)
{
	insert_at(value, index);
}

void IntArray::remove(int index)
{
	assert(index >= 0 && index < m_length);

	if (m_length == 1)
	{
		erase();
		return;
	}

	const int new_length = m_length - 1;
	int* data = new int[new_length];
	for (int i = 0; i < index; ++i)
	{
		data[i] = m_data[i];
	}

	for (int i = index + 1; i < m_length; ++i)
	{
		data[i - 1] = m_data[i];
	}

	delete[] m_data;

	m_data = new int[new_length];
	std::copy(data, data + new_length, m_data);
	m_length = new_length;

	delete[] data;
}

int IntArray::get_length() const
{
	return m_length;
}
