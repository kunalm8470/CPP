#include <iostream>

class Base
{
protected:
    int m_value{};
public:
    Base(int value) : m_value{ value }
    {

    }
};

class Derived : protected Base
{
public:
    Derived(int value) : Base{ value }
    {

    }

    /*
        Base class objects don't have access 
        to the get_value() method

        This way we can extend the functionality
        of the base class without touching the existing
        implementation of the base class
    */
    int get_value() const
    {
        return m_value;
    }
};

int main(int argc, char** argv)
{
    Derived d{ 4 };
    std::cout << "Value= " << d.get_value() << std::endl;

    return 0;
}
