#include <iostream>
#include "Header.h"

inline int find_max(int x, int y)
{
    return x > y ? x : y;
}

/*
    inline functions are exempted from
    One-Definition-Rule (ODR)

    And inline functions with same signatures
    can be there in multiple translation units

    Duplicacy of inline functions is
    considered a bad practice, however the C++
    compiler allows it to build and link
*/
inline void print_message(const char* message)
{
    std::cout << "C-styled string from main file= " << message << std::endl;
}

int main(int argc, char** argv)
{
    /*
        inline functions are just
        expanded at the call-site
        instead of them being pushed
        into the stack-frame and context-switch
        taking place

        Good candidates for inline functions
        include short functions that do not branch

        However modern C++ compilers, inline certain
        function as they see fit for performance gains
    */
    std::cout << "Inline function result= " << find_max(4, 5) << std::endl;
    
    print_message("Kunal");

    return 0;
}
