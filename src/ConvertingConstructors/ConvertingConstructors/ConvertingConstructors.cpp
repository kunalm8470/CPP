#include <iostream>
#include "SomeClass.h"

int main(int argc, char** argv)
{
    MyClass mc(2);
    MyClass mc1{ 3 };

    std::cout << mc;
    std::cout << mc1;

    return 0;
}
