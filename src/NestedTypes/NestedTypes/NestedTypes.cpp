#include <iostream>
#include "Header.h"

int main(int argc, char** argv)
{
    /*
        Accessing nested member 
        function of a struct
    */
    Outer::Inner i;
    i.display_something();

    /*
        Initializing nested scoped-enum
    */
    Fruit apple{ Fruit::FruitType::APPLE };
    apple.print_fruit_type();

    return 0;
}
