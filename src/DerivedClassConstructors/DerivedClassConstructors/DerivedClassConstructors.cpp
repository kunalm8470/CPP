#include <iostream>
#include "Derived.h"

int main(int argc, char** argv)
{
    /*
        1. Memory for base class member variables are allocated
        2. Base class member variables are initialized via 
           the explicit call to the base class constructor 
           in the derived constructor's member initializer list
        3. Memory for derived class members are allocated
        4. Derived class members are initialized
    */
    Derived d{ 1, 3.14 };
    return 0;
}
