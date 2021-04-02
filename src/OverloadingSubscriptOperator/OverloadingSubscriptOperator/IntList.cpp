#include <initializer_list>
#include "IntList.h"

IntList::IntList(std::initializer_list<int> list)
{
	for (const int& item: list)
	{
		m_list.push_back(item);
	}
}

/*
	Allows to mutate the l-value

	Since we can mutate the value
	returned by the index, it needs to
	be a reference and can't be a value
	(References are l-values by default)
	and only l-values can be modified in C++
*/
int& IntList::operator[](int index)
{
	return m_list.at(index);
}

/*
	Constant access to the array item
	without the ability to modify it

	Can be invoked by only constant object(s)
*/
const int& IntList::operator[](int index) const
{
	return m_list.at(index);
}
