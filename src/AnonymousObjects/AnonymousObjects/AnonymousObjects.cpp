#include <iostream>
#include "Header.h"

int main(int argc, char** argv)
{
    /*
        Creating an anonymous object
        and passing to the print_cents
        function, which goes out of scope when
        main() goes out of scope
    */
    print_cents(Cents{ 99 });
    return 0;
}
