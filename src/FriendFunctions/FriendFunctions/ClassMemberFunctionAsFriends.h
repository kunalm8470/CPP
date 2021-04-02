#ifndef CLASS_MEMBER_FUNCTIONS_AS_FRIENDS
#define CLASS_MEMBER_FUNCTIONS_AS_FRIENDS

class B;

class A
{
public:
	void func1(const B& b);
};

class B
{
private:
	int m_b;
public:
	B(int b) : m_b{ b }
	{

	}

	friend void A::func1(const B& b);
};

#endif
