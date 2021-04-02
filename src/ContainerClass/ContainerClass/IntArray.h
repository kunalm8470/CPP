#include <initializer_list>
#include <iostream>

#ifndef INTARRAY_H
#define INTARRAY_H

class IntArray
{
private:
	int* m_data{};
	int m_length;
	void insert_at(int, const int);

public:
	IntArray() = default;
	IntArray(int);
	IntArray(std::initializer_list<int>);
	~IntArray();

	friend std::ostream& operator << (std::ostream&, const IntArray&);
	int& operator[](int);
	const int& operator[](int) const;
	int get_length() const;
	void erase();
	void resize(int);
	void insert(int, int);
	void insert_front(int);
	void insert_rear(int);
	void remove(int);
};

#endif
