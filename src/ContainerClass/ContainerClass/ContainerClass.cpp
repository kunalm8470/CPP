#include <iostream>
#include "IntArray.h"

int main(int argc, char** argv)
{
    IntArray arr{ 5, 4, 3, 2, 1 };    
    arr.resize(8);

    /*
        Setting value via subscript operator
    */
    arr[7] = 9;

    // Accessing value by subscript operator
    std::cout << arr[7] << std::endl;

    arr.insert_front(4);

    arr.insert_rear(80);

    arr.remove(9);

    std::cout << arr;

    return 0;
}
