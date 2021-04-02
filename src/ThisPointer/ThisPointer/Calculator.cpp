#include <iostream>
#include "Calculator.h"

Calculator& Calculator::add(int value)
{
    this->m_x += value;
    return *this;
}

Calculator& Calculator::subtract(int value)
{
    this->m_x -= value;
    return *this;
}

Calculator& Calculator::multiply(int value)
{
    this->m_x *= value;
    return *this;
}

void Calculator::get_value()
{
    std::cout << "Current value= " << this->m_x << std::endl;
}