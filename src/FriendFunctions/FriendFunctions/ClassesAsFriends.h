#ifndef CLASSES_AS_FRIENDS
#define CLASSES_AS_FRIENDS

class Class1
{
	friend class Class2;
private:
	int m_x{};
public:
	Class1(int x) : m_x{ x }
	{

	}
};

class Class2
{
public:
	void mutate_Class1(Class1& c1, int x) const;
};

#endif
