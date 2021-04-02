#include <iostream>

/*
    Destructors are special functions that
    get called when the object goes out of
    scope.

    Destructors don't have overloads and can't
    return anything, they are suited for cleanup
    logic. There is only 1 destructor per class
    as opposed to constructor overloading

    Variables which have automatic duration
    ensure the destructor gets called when the
    variable is about to go out of scope.

    RAII pattern in C++ helps in allocating memory
    from the heap into the constructor and 
    de-allocating the memory back in destructor
    thereby preventing any memory leaks

    The below class is RAII compliant
*/
class Simple
{
    private:
        int m_id{};
    public:
        Simple(int id) : m_id{ id }
        {
            std::cout << "Constructor called with Id= " << id << std::endl;
        }

        int get_id();

        ~Simple()
        {
            std::cout << "Destructor called of Id= " << m_id << std::endl;
        }
};

int Simple::get_id()
{
    return m_id;
}

int main(int argc, char** argv)
{
    Simple s1{ 10 };
    return 0;
}
