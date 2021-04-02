#include <iostream>
#include <string>

enum class Type
{
    INT,
    FLOAT,
    CSTRING
};

void printValue(void* ptr, Type type)
{
    switch (type)
    {
        case Type::INT:
            std::cout << *static_cast<int*>(ptr) << std::endl;
            break;
        case Type::FLOAT:
            std::cout << *static_cast<float*>(ptr) << std::endl;
            break;
        case Type::CSTRING:
            /*
                No de-referencing needed,
                as char* implicitly decays back
                to C-Style strings
            */
            std::cout << static_cast<char*>(ptr) << std::endl;
            break;
    }
}


int main(int argc, char** argv)
{
    int x = 4;
    float f = 4.01;
    char str[]{ "KUNAL" };
    struct Person
    {
        std::string name;
        int age{};
    };
    Person kunal{ "Kunal Mukherjee", 25 };

    void* ptr;
    ptr = &x;

    // Typecast back to int pointer now
    const int* iptr = static_cast<int*>(ptr);
    std::cout << *iptr << std::endl;

    ptr = &f;
    ptr = &kunal;

    printValue(&x, Type::INT);
    printValue(&f, Type::FLOAT);
    printValue(&str, Type::CSTRING);

    return 0;
}
