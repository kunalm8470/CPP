#ifndef HEADER_H
#define HEADER_H

struct Outer
{
	struct Inner
	{
		void display_something();
	};
};

class Fruit
{
public:
	enum class FruitType
	{
		APPLE,
		BANANA,
		CHERRY
	};

	Fruit(FruitType type) : m_type{ type }
	{

	}

	void print_fruit_type();

private:
	FruitType m_type{};
};

#endif