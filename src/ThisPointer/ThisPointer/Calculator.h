#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator
{
    private:
        int m_x{};
    public:
        Calculator() = default;
        Calculator(int x) : m_x(x)
        {

        }

        Calculator& add(int value);
        Calculator& subtract(int value);
        Calculator& multiply(int value);
        void get_value();
};

#endif
