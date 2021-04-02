#include <iostream>
#include <cmath>
#include <algorithm>

/*
Knuth's algorithm
    - Return true if the difference between a and b is within epsilon percent of the larger of a and b
*/
bool approximatelyEqual(double a, double b, double epsilon)
{
    // i.e, |a-b| <= max(a, b) * epsilon
    double diff = std::abs(a - b);
    double epsilonProd = std::max(std::abs(a), std::abs(b)) * epsilon;
    return diff <= epsilonProd;
}

int addNums(int a, int b)
{
    return a + b;
}

int main(char** argv, int argc) {

	/* Using static_cast<> to do floating point division with integers */
    int x{ 7 };
    int y{ 4 };
    int neg = -6;
    double d = 5.0;

    std::cout << "int / int = " << x / y << '\n';
    std::cout << "double / int = " << static_cast<double>(x) / y << '\n';
    std::cout << "int / double = " << x / static_cast<double>(y) << '\n';
    std::cout << "double / double = " << static_cast<double>(x) / static_cast<double>(y) << '\n';

    /* Divide by zero, program will crash */
    int zero = {};
    /* std::cout << x / zero; */

    // Mod operator
    std::cout << "Mod result: " << x % y << '\n';
    std::cout << "Mod result for negative numbers: " << neg % y << '\n';
    
    // C++ doesn't have a exponent operator, using the cmath header to import and use pow() function
    /*
        In the vast majority of cases, integer exponentiation will overflow the integral type. This is likely why such a function wasn’t included in the standard library in the first place.
    */
    double d1{ std::pow(3.0, 4.0) };
    std::cout << d1 << '\n';
    
    // Associativity and precedence example

    /*
        Because * and % have higher precedence than +, the + will evaluate last. We can rewrite our expression as 6 + (5 * 4 % 3). Operators * and % have the same precedence, so we have to look at the associativity to resolve them. The associativity for operators * and % is left to right, so we resolve the left operator first. We can rewrite our expression like this: 6 + ((5 * 4) % 3).
        
        6 + ((5 * 4) % 3) = 6 + (20 % 3) = 6 + 2 = 8
    */
    std::cout << 6 + 5 * 4 % 3 << '\n';

    // Increment / decrement operators, and side effects
    int i2{ 5 };
    int pI2 = ++i2; // x is incremented to 6, x is evaluated to the value 6, and 6 is assigned to y

    std::cout << i2 << ' ' << pI2 << '\n';

    int i3{ 5 };
    int pI3 = i3++; // x is incremented to 6, copy of original x is evaluated to the value 5, and 5 is assigned to y

    std::cout << i3 << ' ' << pI3 << '\n';

    // Comparing floating point numbers
    // dSum is really close to 1.0, but has rounding errors, so it's slightly smaller than 1.0
    double dSum{ 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 };
    bool isApproximatelyEqual = approximatelyEqual(dSum, 1.0, 1e-8);

    // Comma operator
    int i4{ 1 };
    int i5{ 2 };

    // increment x and y, evaluates to the right operand
    std::cout << (++i4, ++i5) << '\n';

    int i6{ 4 };
    // i6 is incremented, then passed as value
    int pRes = addNums(++i6, i6++);

    bool inBigClassroom{ false };
    /* The type of the expressions must match or be convertible, else C++ won't compile
       The compiler will try to find a way to convert the string literal to an integer, but since it 
       doesn’t know how, it will give an error.
    */
    const int classSize{ inBigClassroom ? 30 : 20 };
    std::cout << "The class size is: " << classSize << '\n';

    /* 
        DeMorgan's law can simplify -
        !(x && y) is equivalent to !x || !y
        !(x || y) is equivalent to !x && !y
    */
    
	return 0;
}