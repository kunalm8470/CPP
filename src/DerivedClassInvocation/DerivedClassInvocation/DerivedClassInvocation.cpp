#include <iostream>
#include "Base.h"
#include "Derived.h"

int main(int argc, char** argv)
{
    std::cout << "Invoking the base class" << std::endl;
    Base b;

    std::cout << "Invoking the derived class" << std::endl;
    Derived d;

    return 0;
}
