#include <iostream>
#include <cstdlib>

int get_pseudo_random_number()
{
    return rand() % 100;
}

/*
    For values that are not
    needed often, but are tricky
    to compute, mark it with constexpr
*/
constexpr int sum(int x, int y)
{
    return x + y;
}

constexpr unsigned long long operator"" _KB(unsigned long long no)
{
    return no * 1024;
}

constexpr unsigned long long operator"" _MB(unsigned long long no)
{
    return no * (1024_KB);
}

int main(int argc, char** argv)
{
    /*
        const can contain values
        from runtime resolved function
    */
    const int rand_int = get_pseudo_random_number();

    /*
        constexpr expects a compile-time
        resolved r-value

        constexpr int rand_int2 = get_pseudo_random_number();
    */

    /*
        The debug breakpoint doesn't
        step-in constexpr marked functions
        indicating that they are compiled ahead of time
    */
    constexpr int sum = ::sum(2, 3);

    std::cout << "5 MB is= " << 5_MB << std::endl;

    return 0;
}