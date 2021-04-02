#include <iostream>
#include <cassert>
#include <iterator>
#include <vector>

void print_string(const char* cstring)
{
    /*
        Asserts should be ideally
        only in debug builds and not
        in production builds because
        everytime it incurs a performance
        cost when it runs
    */
    /*
        Also if NDEBUG macro is enabled
        then all asserts are disabled
    */
    /*
        assert only works at runtime and
        terminates the program abnormally
        without the chance of doing cleanup
    */
    // assert(cstring != NULL && "string is null");

    /*
        For compile-time error checking, use
        static_assert
    */
    //static_assert(cstring == NULL, "cstring is null!");
   
    // Only print if cstring is non-null
    if (cstring)
        std::cout << cstring << std::endl;
    else
        std::cerr << "function printString() received a null parameter" << std::endl;
}

int getArrayIndex(const int (&arr)[5], int index)
{
    if (index < 0 || index >= static_cast<int>(std::size(arr)))
    {
        return -1;
    }

    return arr[index];
}

int main(int argc, char** argv)
{
    int arr[] = { 5, 4, 3, 2, 1 };
    std::cout << "Manually checking array bounds: " << getArrayIndex(arr, 2) << std::endl;
    print_string(NULL);


    return 0;
}
