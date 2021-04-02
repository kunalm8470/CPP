#include <iostream>
#include "Cents.h"

int main(int argc, char** argv)
{
    Cents c1{ 90 };

    /*
        Overloading the + operator
    */
    Cents c2 = c1 + 10;

    std::cout << "New cents= " << c2.get_cents() << std::endl;
    return 0;
}
