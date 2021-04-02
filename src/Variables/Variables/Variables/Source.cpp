#include <iostream>
#include "Header.h"
#include "Constants.h"

/*
    By convention, global variables are declared at the top of a file, 
    below the includes, but above any code
*/
/*
    Use "g" or "g_" prefix for global variables 
    to help differentiate them from local variables
*/
/*
    Global variables have file scope, which means
    they are accessible from the point of declaration to
    the end of the file they are declared in.

    Global variables have static duration, i.e
    they are created when the program starts and
    destroyed when the program ends
*/
int g_x = 10;

/*
    Constant global variables need to be 
    initialized before used
*/
const int g_y = 20;
constexpr int g_z = 30;

/*
    Non-constant globals have external linkage by default,
    but can be given internal linkage via the static keyword
*/
static int g_a = 35;

int doSomething(int x, int y)
{
    return x * y;
}

/*
    doOtherThing has internal linkage because of the static modifier
    By default functions have external linkage
*/
static int doOtherThing(int a, int b) 
{
    return a % b;
}

namespace foo // define a namespace named foo
{
    // This doSomething() belongs to namespace foo
    int doSomething(int x, int y)
    {
        return x + y;
    }
}

namespace goo // define a namespace named goo
{
    // This doSomething() belongs to namespace goo
    int doSomething(int x, int y)
    {
        return x - y;
    }
}

int max(int x, int y) // x and y enter scope here
{
    // assign the greater of x or y to max
    int max{ (x > y) ? x : y }; // max enters scope here

    return max;
} // x, y, and max leave scope here here

/*
    Forward declaration provided here
*/
bool isOdd(int);

void incrementAndPrint()
{
    /* 
        static duration via static keyword.  
        This initializer is only executed once. 
    */
    /*
        By convention, prefix static variables
        with s_
    */
    static int s_value = 1; 
    ++s_value;
    std::cout << s_value << '\n';
} // s_value is not destroyed here, but becomes inaccessible because it goes out of scope

/*
    From C++14 we can specify auto return
    types and automatic type inference will take
    place
*/
auto add(double d1, double d2, double d3)
{
    return d1 + d2 + d3;
}

/*
    Using trailing return type syntax makes
    in long function names "lined up" neatly for
    greater readibility
*/
auto divide(double x, double y) -> double
{
    return x / y;
}

/*
    Unnamed namespace
*/
namespace
{
    void doThatThing() // can only be accessed in this file
    {
        std::cout << "v1\n";
    }
}

int main(int argc, char** argv) {
    //***********************************Compound blocks***********************************
	// Inner/nested block
	{
		std::cout << "Inside compound statement!\n";
	}

	std::cout << "Outside compound statement!\n";
    std::cout << foo::doSomething(2, 3) << std::endl;
    std::cout << goo::doSomething(2, 3) << std::endl;

    //***********************************Namespaces***********************************
    // This is calling the global namespace doSomething
    std::cout << ::doSomething(2, 3) << std::endl;

    /* 
        Calling some other function in 
        same namespace but different file
    */
    std::cout << foo::doOther(4, 3) << std::endl;

    /*
        Nested namespace example
    */
    std::cout << bar::baz::add(1, 2) << std::endl;

    /*
        We can also alias namespaces 
        to reduce redundancy
    */
    namespace gaz = bar::baz;
    std::cout << gaz::add(2, 2) << std::endl;

    std::cout << ::max(2, 3) << std::endl;


    //***********************************Local variables***********************************
    int x = { 4 };

    /*
        Local variables have automatic storage duration, 
        which means they are created at the point of definition
        and destroyed at the end of the block they are defined in.
    */
    /*
        Local variables inside a block should have unique name(s)
    */
    {
        int x = 3; // x is created
        int y = 4; // y is created

        std::cout << "Inner x: " << x << std::endl;
    } // x and y's are destroyed here

    /*
        Local variables have no linkage, 
        which means that each declaration refers to a unique object.
    */
    std::cout << "Outer x: " << x << std::endl;

    //***********************************Global variables***********************************
    std::cout << "Global x: " << ::g_x << std::endl;
    std::cout << "Global y: " << ::g_y << std::endl;
    std::cout << "Global z: " << ::g_z << std::endl;

    //***********************************Variable shadowing***********************************
    /*
        Variable shadowing should be avoided as
        it causes unindented side-effects and subtle bugs
        which are hard to catch
    */
    /*
        Case 1. Shadowing of local variables
    */
    int apples = 5;

    {
        // apples refers to outer block apples here
        std::cout << apples << '\n';

        int apples;

        /* 
            apples now refers to the nested block apples
            the outer block apples is temporarily hidden
        */
        apples = 10; // this assigns value 10 to nested block apples, not outer block apples

        std::cout << apples << '\n'; // print value of nested block apples
    } // nested block apples destroyed

    std::cout << apples << '\n';

    /*
        Case 2. Shadowing of global variables
    */
    // Hides the global variable value until the end of this block
    int g_x = 25;
    g_x += 2;
    std::cout << "Shadowed global variable: " << g_x << '\n';

    //***********************************Internal linkage***********************************
    /*
        An identifier with internal linkage can be seen 
        and used within a single file. 
        
        But its not accessible from other files (i.e, its not exposed to the linker). 
        This means that if two files have identically named identifiers with internal linkage, 
        those identifiers will be treated as independent.
    */
    std::cout << "Static global a: " << g_a << "\n";

    /*
        Because linkage is a property of an identifier (not of a variable), 
        function identifiers have the same linkage property that variable identifiers do. 
        
        Functions default to external linkage, but can be set to internal linkage via the static keyword.
    */
    std::cout << doOtherThing(43, 11) << std::endl;

    //***********************************External linkage***********************************
    /*
        An identifier with external linkage can be seen 
        and used both from the file in which it is defined, 
        and from other code files (via a forward declaration).
    */
    std::cout << static_cast<bool>(isOdd(11)) << "\n";

    //***********************************Global constants and inline variables***********************************
    std::cout << "Gravity on this planet is: " << constants::my_gravity << "\n";

    //***********************************Static local variables***********************************
    ::incrementAndPrint();
    ::incrementAndPrint();
    ::incrementAndPrint();

    //***********************************Typedefs and Type aliases***********************************
    /*
        Typedefs allow us to create an alias for the type,
        they have the same storage and scoping rules as variables.

        Suffix _t to typedef(s) as convention
    */
    {
        typedef long miles_t;
        miles_t dist = 100000;
    }

    /*
        type alias syntax is cleaner for more advanced typedefing cases, 
        and should be preferred.
    */
    {
        using distance_t = double;
        distance_t dist = 1000000000.45;
    }

    //***********************************Type inference using auto keyword***********************************
    
    // Type inference for variables
    auto a = 2.2;

    //***********************************Implicit type conversion (coercion)***********************************
    /*
        A double initialized with an integer value
        Here implicit type conversion takes place
    */
    double d = 6;

    /*
        Division between a double an integer
    */
    double division{ 4.0 / 3 };

    /*
        Integral promotion includes a narrower type
        like int/short to promote into a more broad type
        via long or long long via padding extra 0(s) internally
    */
    long l{ 64 };

    /*
        Promote the float 0.12 into a double
    */
    double d{ 0.12f };

    //***********************************Explicit type conversion (casting) and static_cast***********************************

    /*
        Explicit casting can be done in a variety of ways
        1. C-style casts
        2. static casts
        3. dynamic casts
        4. reinterpret casts
    */

    /*
        Exhibit a) C-Style Casts, Done using () operator

        The right operand will also be converted to a float value
        before doing the actual division
    */
    int i1{ 10 };
    int i2{ 4 };
    float f{ (float)i1 / i2 };

    /*
        Exhibit b) Static casts in C++ can be done using static_cast operator
    */
    char c = 'a';
    std::cout << c << ' ' << static_cast<int>(c) << '\n';
 
    //***********************************Unnamed and inline namespaces***********************************
    
    /*
        No need of prefixing the namespace using scope resolution operator
        As the namespace is unnamed
    */
    doThatThing();

	return 0;
}