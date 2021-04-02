#include <iostream>

/*
    function() here is a
    overloaded function whose return type
    is the same but signature is different

    Function overloading in C++ allows -
    1. Number of arguments to be different
    2. Type of arguments to be different
   
    Things which should remain same -
    1. Function return type
    2. Function name
    3. No support of typedef names
*/
int function(int a)
{
    return a + 5;
}

int function(int b, int c)
{
    return b + c;
}

/*
    // Invalid, because typedef
    // doesn't create a new type
    // altogether, hence this is
    // not eligible for function overloading

    typedef char *string;
    void print(string value);
    void print(char *value);
*/

/*
    3 stratergies how function calls are matched
    to their respective defintions

    1. Exact match of the signature is found
       The call is resolved to the particular
       overloaded function

       E.g: 
       void print(char* msg);
       void print(int a);

       print(3);

    2.  No exact match of the signature
        is found (i.e the arguments can't be resolved
        to any overloaded function)

        C++ will try to promote implicitly via type conversion
        - char, unsigned char, short are converted to int
        - unsigned short will be converted to unsigned int
        - float is converted to double
        - enum is promoted to int

        E.g:
         void print(char* msg);
         void print(int a);

         print('a'); // This will try to match the int overload

         If no promotion is possible, C++ will try to match
         through the standard promotion
         - int to float
         - enum will match any numeric type (float / double)
         - zero will match pointer type or any numeric type (float / double)
         - pointer will match void pointer
        
         Lastly it will look through user-created types
         like classes and structures

    3.  Ambiguous matches are compile-time errors
        and need to be disambiguated before the prorgram
        compiles (To do this we can use <static_cast>(<type>))
*/

void fcn(char c, int x)
{
    std::cout << 'a' << std::endl;
}

void fcn(char c, double x)
{
    std::cout << 'b' << std::endl;
}

void fcn(char c, float x)
{
    std::cout << 'c' << std::endl;
}

int main(int argc, char** argv)
{
    // Call the overloaded functions
    std::cout << "Overloaded function 1= " << ::function(2) << std::endl;
    std::cout << "Overloaded function 2= " << ::function(2, 3) << std::endl;

    /*
        This tries to match the first overloaded
        function, as its an exact match
    */
    ::fcn('a', 4);

    /*
        To be double sure
    */
    ::fcn('a', static_cast<int>(4));
    ::fcn('b', static_cast<float>(4));

    return 0;
}
