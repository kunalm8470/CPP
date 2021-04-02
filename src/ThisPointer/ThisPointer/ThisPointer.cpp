#include <iostream>
#include "Calculator.h"

/*
    The this pointer is only
    accessible by non-static members of a class/struct

    Each object gets its own copy
    of data members and member functions

    The this pointer is passed to all
    non static member functions as a hidden parameter

    The this pointer is a r-value (i.e its non modifiable)
    it results in a compile error if we try to assign to it,
    however older C++ compilers may allow it, but modern compilers don't
*/
class T
{
    private:
        int m_x = 4;
        int m_y{};
        double m_d{};

    public:
        T() = default;

        T(int x) : m_x(x),
                    m_y(this->m_x)
        {

        }

        /*
            Function chaining by returning
            the de-referencing the this pointer
        */
        T& set_int(int x)
        {
            this->m_x = x;
            return *this;
        }

        T& set_double(double d)
        {
            this->m_d = d;
            return *this;
        }

        
        /*
            void change(T* t) 
            { 
                this = t; 
            }
        */
};



int main(int argc, char** argv)
{
    T t(45);

    /*
        Functions can be chained in
        any order
    */
    t.set_double(3.14).set_int(3);
    t.set_int(3).set_double(3.14);

    Calculator calc(10);
    calc.add(10).subtract(10).multiply(10);
    calc.get_value();
}
