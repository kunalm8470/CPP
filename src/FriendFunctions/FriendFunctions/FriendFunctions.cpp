#include <iostream>
#include "Accumulator.h"
#include "Weather.h"
#include "ClassMemberFunctionAsFriends.h"
#include "ClassesAsFriends.h"

int main(int argc, char** argv)
{
    Accumulator acc;
    acc.accumulate(20);

    // Inline friend function called
    print_accumulated(acc);

    // Friend function called
    reset(acc);
    
    /*
        print_weather() is
        common friend function in both
        temperature and humidity class
    */
    Temperature temp{ 23 };
    Humidity h{ 85 };
    print_weather(temp, h);

    /*
        Accessing class b from
        class A's member function
    */
    A a;
    B b{ 2 };
    a.func1(b);

    /*
        The entire class 1 is a
        friend to class 2
    */
    Class1 c1{ 10 };
    Class2 c2;
    c2.mutate_Class1(c1, 20);

    return 0;
}
