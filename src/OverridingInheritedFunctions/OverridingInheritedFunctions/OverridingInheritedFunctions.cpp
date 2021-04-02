#include <iostream>

class Base
{
protected:
    int m_value{};
public:
    Base(int value) : m_value{ value }
    {

    }

    void identify()
    {
        std::cout << "Base class identified!" << std::endl;
    }

    friend std::ostream& operator << (std::ostream& out, const Base& b)
    {
        out << "Base value= " << b.m_value << std::endl;
        return out;
    }
};

class Derived : public Base
{
    // We can hide m_value from other place
private:
    using Base::m_value;
public:
    Derived(int value) : Base{ value } 
    {

    }

    /*
        When we provide the implementation of
        base class method it takes the re-defined function
        instead of the base one
    */
    void identify()
    {
        /*
            We can call the base class method using
            the scope resolution operator
        */
        Base::identify();

        std::cout << "Derived class identified!" << std::endl;
    }

	friend std::ostream& operator << (std::ostream& out, const Derived& d)
	{
        /*
            Other way is to typecast it to base-class
            value
        */
        out << static_cast<Base>(d);

		out << "Derived value= " << d.m_value << std::endl;
		return out;
	}
};

int main(int argc, char** argv)
{
    Base b{ 5 };
    b.identify();

    Derived d{ 7 };
    d.identify();

    return 0;
}
