#include <iostream>
#include "Matrix.h"

int main(int argc, char** argv)
{
    Matrix m;

    std::cout << "Element at (4, 5) is= " << m(3, 4) << std::endl;
    return 0;
}
