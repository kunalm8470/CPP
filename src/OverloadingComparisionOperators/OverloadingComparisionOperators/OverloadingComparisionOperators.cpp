#include <iostream>
#include "Car.h"

int main(int argc, char** argv)
{
    Car c1{ "Toyota", "Corolla" };
    Car c2{ "Toyota", "Camry" };

    if (c1 == c2)
    {
        std::cout << "Both cars have same make and model!";
    }
    else
    {
        std::cout << "Both cars have different make and model!";
    }

    return 0;
}
