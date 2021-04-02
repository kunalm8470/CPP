#include <iostream>
#include <array>
#include "s.h"

/*
    We can declare the prototype first
    so as to give the forward reference
    and define the function at a later stage in
    the code
*/
int function_prototype(int);

/*
    Formal parameters
    This is pass-by-value

    We can pass arguments to
    a function using 3 techniques

    1. pass-by-value
    2. pass-by-pointer
    3. pass-by-reference

    x & y are created here
*/
void foo(int x, int y)
{
    std::cout << "x = " << x << "y = " << y << std::endl;
} // x and y are destroyed here

/*
    1. Pass-by-value
    Pass primitive values by value

    Don't pass struct, enum or class using value
    if the function is being called repeatedly,
    as it causes performance penalty
*/
void bar(int y)
{
    /*
        Increment made to the temporary value passed,
        no effect to the original value being passed
    */
    y += 1;
    std::cout << "y = " << y << std::endl;
}

/*
    2. Pass-by-pointer
    The function parameter must be a pointer

    The function can de-reference the pointer
    and access / change the value
*/
void baz(int* z)
{
    /*
        Making change to the referenced value from
        the called function using pointer reflects 
        the original value too
    */
    *z += 5;
    std::cout << "De-referenced value= " << *z << std::endl;
}

/*
    Arrays when passed to a function
    decays to a pointer, losing its 
    length value, hence needing it to passed
    from the call-site
*/
void qux(int* arr, size_t n)
{
    // Fail early
    if (arr == 0)
    {
        return;
    }

    for (size_t i = 0; i < n; i++)
    {
        std::cout << *(arr + i) << " ";
    }
    std::cout << std::endl;
}

/*
    C-styled character arrays
    can be printed implicitly
    without the need of any explicit
    pointer arithmetic using printf or std::cout
*/
void qux(const char* c_str)
{
    // Fail early
    if (!c_str) 
    {
        return;
    }

    std::cout << "C-Style array= " << c_str;
}

/*
    When allocating memory for
    an array dynamically, or using 
    a pointer return the pointer to it
*/
int* allocateArray(int size)
{
    return new int[size];
}

/*
    3. Pass-by-reference (Only C++, not in C)
    Pass the reference to the original variable itself

    Any changes, made in the original function
    will be reflected in the main function too
*/
void swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

/*
    When passing huge structs or class,
    its advisable to use pass-by-reference

    arr[index] doesn't go out of scope as its a
    reference and returns the exact value that the
    original array is pointing to
*/
int& get_element_by_index(std::array<int, 25>& arr, size_t index)
{
    return arr[index];
}

/*
    main() is a special function in C++
    where a return value is optional, and
    it implicitly returns 0
*/
int main(int argc, char** argv)
{
    /*
        Passing r-value directly to the function
    */
    std::cout << "Function prototype= " << function_prototype(5) << std::endl;

    int x = 4, y = 5;
    /*
        Passing l-values
    */
    foo(x, y);

    /*
        Passing r-values
    */
    foo(6, 7);

    /*
        Call function, where arguments 
        are passed by value
    */
    bar(5);

    /*
        Call function, where arguments
        are passed by pointer
    */
    baz(&x);
    
    int arr[] = { 5, 4, 3, 2, 1, 0 };

    qux(arr, 6);
    qux("Kunal");
    std::cout << std::endl;

    /*
        Call function, where arguments
        are passed by reference
    */
    int& x_ref = x;
    int& y_ref = y;
    swap(x_ref, y_ref);

    /*
        Allocate memory dynamically
        from the heap, in row major order

        The allocateArray function returns a pointer
        to the first address of the newly allocated
        dynamic array
    */
    int* arr2 = allocateArray(34);

    /*
        De-allocate memory back to
        the heap
    */
    delete[] arr2;


    std::array<int, 25> arr3{};
    get_element_by_index(arr3, 0) = 1;

    S s1;
    initialize_S(s1);
    std::cout << "S.c= " << s1.c << " and S.a= " << s1.a << std::endl;

    return 0;
}

/*
    Function definition of the 
    above declared prototype here
*/
int function_prototype(int x)
{
    return x + 4;
}