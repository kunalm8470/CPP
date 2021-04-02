#include <iostream>

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

int main(int argc, char** argv)
{
    int var1;

    /*
        var2 is a reference variable,
        holds same value as var1
    */
    int& var2 = var1;
    var1 = 10;

    std::cout << "var1 = " << var1 << std::endl;
    std::cout << "var2 = " << var2 << std::endl;

    /*
        Both var1 and var2 point to 
        the same memory location
    */
    std::cout << "Address var1 = " << &var1 << std::endl;
    std::cout << "Address var2 = " << &var2 << std::endl;

    // Invalid, needs to reference something
    // int& invalidRef; 

    /*
        A reference variable provides an alias 
        for a previously defined variable.

        References cannot be null, whereas pointers can.
        Every reference refers to some object, 
        although it may or may not be valid.
    */
    int x = 10, y = 20;
    swap(x, y);
    std::cout << "x = " << x << ", y = " << y << std::endl;

    /*
        Once initialized, a reference can't be 
        changed to reference another variable.
    */
    int x1 = 5, x2 = 6;
    int& ref = x1;
    ref = x2;
    std::cout << x1 << std::endl;

    return 0;
}
