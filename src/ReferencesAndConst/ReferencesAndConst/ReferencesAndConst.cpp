// ReferencesAndConst.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

/*
    Pass by const-ref
    when we don't want to
    mutate the parameter,
    also it takes valid r-values
*/
void print(const int& r)
{
    std::cout << r << std::endl;
}

int main(int argc, char** argv)
{
    // Valid l-value
    int x = 5;
    const int& ref1 = x;

    // Valid l-value
    const int y = 6;
    const int& ref2 = y;

    // Valid r-value
    const int& ref3 = 6;
    std::cout << "ref3 = " << ref3 << std::endl;

    // Valid r-value
    print(2 + 2);

    // Valid l-value
    print(ref1);

    // Valid l-value
    print(ref2);

    return 0;
}
