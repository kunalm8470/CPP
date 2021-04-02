#include <iostream>
#include <string>
#include "Date.h"

/*
    We can overload non-const and const
    member function also
*/
class Something
{
    private:
        std::string m_str{};

    public:
        Something() = default;
        Something(const std::string str) : m_str(str)
        {

        }

        const std::string& get_value() const
        {
            return this->m_str;
        }

        std::string& get_value()
        {
            return this->m_str;
        }
};

int main(int argc, char** argv)
{
    Date today{ 2020, 9, 25 };
    to_string(today);

    // Calls non const overload of get_value()
    Something s1;
    s1.get_value() = "Kunal";


    // Calls const overload of get_value()
    const Something s2("John Doe");
    s2.get_value();

    return 0;
}
