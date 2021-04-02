#include <iostream>
#include <cstdarg>

/*
    If more than paramN arguments
    are passed then that will be ignored

    If less than paramN arguments are
    passed then the remaining arguments will be
    garbage
*/
void print_ints(int count, ...)
{
    /*
        va_list esentially is a
        pointer that points to the ellipsis array
    */
    va_list args;

    /*
        va_start takes 2 parameters
        va_list and the last non-ellipse
        parameter and points the arguments to
        the actual ellipse array
    */
    va_start(args, count);

    for (int i = 0; i < count; ++i)
    {
        /*
            To get the value of the actual parameter
            from the ellipse array
        */
        std::cout << va_arg(args, int) << " ";
    }
    std::cout << std::endl;

    /*
        Cleaning up using va_end
    */
    va_end(args);
}


int main(int argc, char** argv)
{
    print_ints(5, 5, 4, 3, 2, 1);
    print_ints(3, 2, 1);
}
