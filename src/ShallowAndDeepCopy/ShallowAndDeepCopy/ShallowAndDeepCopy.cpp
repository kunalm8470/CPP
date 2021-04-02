#include <iostream>
#include "MyString.h"

int main(int argc, char** argv)
{
    MyString msg{ "Hello world!" };
    {
        MyString dump = msg;
    }
    std::cout << msg.get_data();

    return 0;
}
