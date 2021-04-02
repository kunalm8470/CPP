#include <iostream>
#include "Point.h"

int main(int argc, char** argv)
{
    Point p1{ 2, 2, 2 };

    std::cout << "Pre incremented p1= " << (++p1);
    std::cout << "Pre decremented p1= " << (--p1);


    std::cout << "Post incremented p1= " << (p1++);
    std::cout << "Post decremented p1= " << (p1--);

    return 0;
}
