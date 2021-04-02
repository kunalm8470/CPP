#include <iostream>
#include <array>

struct House
{
    int number{};
    int stories{};
    int roomsPerStory{};
};

struct Array
{
    House value[3]{};
};

void printLength(const std::array<double, 5>& myArray)
{
    /*
        Because std::array doesn't decay into
        a pointer when passed into a function
        we can use the .size() function inside the
        function also
    */
    std::cout << "length: " << myArray.size() << '\n';
}


int main(int argc, char** argv)
{
    std::array<int, 5> iArr;

    // Initializer list
    std::array<int, 5> iArr2 = { 5, 4, 3, 2, 1 };

    // Uniform initialization
    std::array<int, 3> iArr3{ 40, 30, 20 };

    /*
        Since C++17 the type and length
        can be omitted together, but not either
    */
    std::array iArr4{ 4, 3, 2, 1, 0 };

    /*
        Subscript operator [] 
        doesn't apply bounds checking
    */
    std::cout << iArr2[0] << std::endl;

    /*
        To do bounds checking, we use
        the .at() function

        It throws std::out_of_range exception
        if tried to access invalid address

        We can also set the value at the 
        particular index using the .at()
        function
    */
    std::cout << iArr2.at(4) << std::endl;
    iArr.at(0) = 1;

    /*
        std::array provides the .size() function
        to fetch the length
    */
    size_t iArr_size = iArr.size();
    std::cout << "Length of iArr= " << iArr_size << std::endl;

    /*
        Aggregate initialization
    */
    Array houses
    {
        { 
            { 13, 4, 30 }, 
            { 14, 3, 10 }, 
            { 15, 3, 40 } 
        }
    };

    for (const auto& house : houses.value)
    {
        std::cout << "House number " << house.number
            << " has " << (house.stories * house.roomsPerStory)
            << " rooms\n";
    }

    return 0;
}
