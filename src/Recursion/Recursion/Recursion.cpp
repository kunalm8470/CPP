#include <iostream>
#include <iterator>
#include <vector>

/*
    Memoized recursive call
    to the fibonacci function
*/
int fibonacci(int nth_num)
{
    static std::vector<int> results{ 0, 1 };

    if (nth_num < static_cast<int>(std::size(results)))
    {
        return results[nth_num];
    }
    else
    {
        results.push_back(fibonacci(nth_num - 1) + fibonacci(nth_num - 2));
        return results[nth_num];
    }
}

size_t digit_sum(size_t digit)
{
    if (digit == 0)
    {
        return 0;
    }

    size_t quotient = static_cast<size_t>(digit / 10);
    size_t rem = digit - (quotient * 10);
    return rem + digit_sum(quotient);
}

void print_binary(int dec)
{
    if (dec == 0)
    {
        return;
    }

    print_binary(dec / 2);
    std::cout << dec % 2;
}

int main(int argc, char** argv)
{
    std::cout << "Printing first 10 fibonacci numbers using recursive function" << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        std::cout << fibonacci(i) << " ";
    }
    std::cout << std::endl;

    std::cout << digit_sum(357) << std::endl;
    print_binary(148);

    return 0;
}
