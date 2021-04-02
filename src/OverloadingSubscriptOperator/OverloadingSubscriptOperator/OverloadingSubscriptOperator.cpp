#include <iostream>
#include "IntList.h"

int main(int argc, char** argv)
{
    IntList list{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    list[4] = 50;
    std::cout << "5th element is= " << list[4] << std::endl;

    const IntList const_list{ 5, 4, 3, 2, 1 };
    std::cout << "3rd element is= " << list[2] << std::endl;
    return 0;
}
