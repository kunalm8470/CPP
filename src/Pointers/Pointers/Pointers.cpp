#include <iostream>
#include <typeinfo>
#include <cstddef>

void f(std::nullptr_t nullp)
{
    // nullptr is of type std::nullptr_t
    std::cout << typeid(nullp).name() << std::endl;
}

int main(int argc, char **argv)
{
    int x = 5;
    // Prints memory location of x
    std::cout << &x << std::endl;

    // Dereferencing a pointer
    std::cout << *&x << std::endl;

    int *ptr = &x;
    std::cout << ptr << std::endl;

    // To print the type of pointer, use typeid function
    std::cout << typeid(ptr).name() << std::endl;

    /*
        Re-assigning the value of the variable
        through a pointer
    */
    *ptr = 7;

    // Print the size of a pointer
    std::cout << sizeof(ptr) << std::endl;

    // Print the size of the actual variable, the pointer is pointing to
    std::cout << sizeof(x) << std::endl;

    // Initialize null pointer using nullptr keyword (C++11 and above)
    int *i_ptr = nullptr;
    std::cout << i_ptr << std::endl;

    f(nullptr);
    return 0;
}
