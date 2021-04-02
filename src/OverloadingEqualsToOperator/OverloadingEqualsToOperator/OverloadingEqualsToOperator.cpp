#include <iostream>
#include "Fraction.h"

int main(int argc, char** argv)
{
    Fraction f1{ 3, 4 };
    Fraction f2, f3;
    f2 = f3 = f1;

    f2.set_numerator(4).set_denominator(5);

    std::cout << f1;
    std::cout << f2;
    std::cout << f3;

    return 0;
}

