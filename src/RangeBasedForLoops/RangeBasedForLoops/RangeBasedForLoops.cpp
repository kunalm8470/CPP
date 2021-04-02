#include <iostream>

int main(int argc, char** argv)
{
    int arr[] = { 0, 1, 1, 2, 3, 5, 8 };

    /*
        Access the loop variable using
        constant reference wherever 
        possible instead of passing by value
    */
    std::cout << "Printing fibbonaci sequence using range based for loop " << std::endl;
    for (const int& item : arr)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    /*
        Using auto keyword when we want
        to implicitly refer the type

        Using without const references,
        copies it by value
    */
    int arr2[] = { 5, 4, 3, 2, 1 };
    for (auto item: arr2)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    /*
        Item contains the reference
        to the original array item and
        this can be mutated
    */
    for (auto& item : arr2)
    {
        item += 2;
    }

    /*
        If we want to pass references
        to the original item without any
        intention to modify it, then use constant
        references
    */
    for (auto const& item : arr2)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    return 0;
}
