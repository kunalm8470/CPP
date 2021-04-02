#include <initializer_list>
#include <vector>

#ifndef INTLIST_H
#define INTLIST_H

class IntList
{
private:
	std::vector<int> m_list {};

public:
	IntList() = default;
	IntList(std::initializer_list<int>);
	int& operator [](int index);
	const int& operator[](int index) const;
};

#endif
