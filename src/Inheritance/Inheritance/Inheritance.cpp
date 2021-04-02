#include <iostream>
#include "Employee.h"

int main(int argc, char** argv)
{
    Employee kunal{ 001 };
    kunal.m_name = "Kunal";
    kunal.m_age = 25;

    std::cout << kunal;
    return 0;
}
