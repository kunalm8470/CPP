#include <iostream>
#include "Cents.h"

int main(int argc, char** argv)
{
    Cents c1{ 3 };
    Cents c2{ 5 };
    Cents add{ c1 + c2 };
    Cents diff{ c1 - c2 };
    Cents prod{ c1 * c2 };


    return 0;
}
