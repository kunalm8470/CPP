#include <iostream>
#include "Header.h"

void print_values(int x, int y)
{
    std::cout << "x = " << x << ", y = " << y << std::endl;
}

void foo(int x, int y, int z)
{
    std::cout << "Foo x = " << x << ", ";
    std::cout << "Foo y = " << y << ", ";
    std::cout << "Foo z = " << z;
    std::cout << std::endl;
}

/*
    Namespace level functions
    can be prefixed using the
    scope-resolution operator
    and accessed as follows
*/
void bar::baz(float b, float c)
{
    std::cout << "Namespace level baz b = " << b << ", ";
    std::cout << "Namespace level baz c = " << c;
    std::cout << std::endl;
}

void baz(float b, float c)
{
    std::cout << "Baz b = " << b << ", ";
    std::cout << "Baz c = " << c;
    std::cout << std::endl;
}

int main(int argc, char** argv)
{
    print_values(4); // Calls print_values(4, 10);
    print_values(3, 4); // Calls print_values(3, 4);

    foo(1); // Calls foo(1, 4, 5);
    foo(1, 2); // Calls foo(1, 2, 5);
    foo(1, 2, 3); // Calls foo(1, 2, 3);

    baz(3.14); // Calls baz(3.14, 3.997);
    baz(3.14, 6.28); // Calls baz(3.14, 6.28);

    bar::baz(3.14); // Calls bar::baz(3.14, 4.1);
    bar::baz(3.14, 6.28); // Calls bar::baz(3.14, 6.28);

    return 0;
}
