#include <iostream>

class Base 
{
private:
    int m_private{};
protected:
    int m_protected{};
public:
    int m_public{};
};

class Pub : public Base
{
public:
    Pub()
    {
        // m_public accessible publicly
        m_public = 1;

        // m_protected accessible protectedly
        m_protected = 2;

        // m_private inaccessible from derived class in-spite of public
    }
};

class Pro : protected Base
{
public:
    Pro()
    {
        // m_public derived protectedly
        m_public = 1;

        // m_protected derived protectedly
        m_protected = 2;

        // m_private inaccessible as its private
    }
};

class Pro1 : protected Pro
{
public:
    Pro1()
    {
        m_public = 20;
        m_protected = 30;
    }
};

class Pri : private Base
{
public:
    Pri()
    {
        // m_public is only accessible within the class
        m_public = 1;

        // m_protected is only accessible within the class
        m_protected = 2;

        // m_private inaccessible as its private
    }
};

int main(int argc, char** argv)
{
    Base b;

    Pub pu;
    // pu.m_protected inaccessible outside class but accessible in derived class

    Pro pro;
    // pu.m_public inaccessible outside class but accessible in derived class

    /* 
        Control first goes to base class of Pro1, i.e Pro and allocates memory
        and post that comes into the constructor of Pro1
    */
    Pro1 p1;

    Pri pri;

    return 0;
}
