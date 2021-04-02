#include <iostream>

enum class Color
{
    black,
    white,
    red,
    green,
    blue
};

void printColor(Color color)
{
    /*
        Switch expression must evaluate to
        char, short, int, long, long long, or enum
    */
    /*
        We can declare (but not initialize) variables 
        inside the switch, both before and after the case labels.
    */
    switch (color)
    {
        case Color::black:
            std::cout << "Black";
            break;
        case Color::white:
            std::cout << "White";
            break;
        case Color::red:
            std::cout << "Red";
            break;
        case Color::green:
            std::cout << "Green";
            break;
        case Color::blue:
            std::cout << "Blue";
            break;
        default:
            std::cout << "Unknown";
            break;
    }
}

void floydTriangle1() 
{
    int count = 5;
    while (count > 0)
    {
        int t = count;
        while (t > 0)
        {
            std::cout << t << " ";
            t -= 1;
        }
        std::cout << "\n";
        count -= 1;
    }
}

void floydTriangle2()
{
    int count = 1;
    int outerLimit = 5;

    while (count <= outerLimit)
    {
        int inner = { outerLimit - count };
        int i = 0;
        while (i < inner)
        {
            std::cout << "*";
            i += 1;
        }
        
        i = count;
        while (i > 0)
        {
            std::cout << i << " ";
            i -= 1;
        }
        std::cout << "\n";
        count += 1;
    }
}

void makeSelection()
{
    int selection;
    do
    {
        std::cout << "Please make a selection: \n";
        std::cout << "1) Addition\n";
        std::cout << "2) Subtraction\n";
        std::cout << "3) Multiplication\n";
        std::cout << "4) Division\n";
        std::cin >> selection;
    } while (selection != 1 && selection != 2 && selection != 3 && selection != 4);

    std::cout << "You selected option #" << selection << "\n";
}

void countToTen()
{
    for (int count{ 0 }; count < 10; ++count) 
    {
        std::cout << count << ' ';
    }
}

int main(int argc, char** argv)
{
    //**********************************************if, else and else-if statement**********************************************
    std::cout << "Enter a number: ";
    int x;
    std::cin >> x;

    if (x > 10)
    {
        std::cout << x << " is greater than 10\n";
    }     
    else if (x < 10)
    {
        std::cout << x << " is less than 10\n";
    }
    else
    {
        std::cout << x << " is exactly 10\n";
    }
    
    //**********************************************switch statement**********************************************
    ::printColor(Color::green);
    
    //**********************************************goto statement**********************************************
    /*
        double d;
        tryAgain:
            std::cout << "Enter a non-negative number";
            std::cin >> d;

            if (d < 0.0)
                goto tryAgain; // this is the goto statement

            std::cout << d << std::endl;
    */
    
    //**********************************************while statement**********************************************
    ::floydTriangle1();
    std::cout << std::endl;
    ::floydTriangle2();

    //**********************************************do-while statement**********************************************
    std::cout << std::endl;
    ::makeSelection();

    //**********************************************for statement**********************************************
    std::cout << std::endl;
    ::countToTen();

    //**********************************************break and continue statements**********************************************
    std::cout << std::endl;
    for (int count{ 0 }; count < 20; ++count)
    {
        // if the number is divisible by 4, skip this iteration
        if ((count % 4) == 0)
        {
            continue; // jump to end of loop body
        }
        else if (count == 16)
        {
            break;
        }
        // If the number is not divisible by 4, keep going
        std::cout << count << std::endl;
    }

	return 0;
}