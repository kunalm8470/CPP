#include <iostream>

int main(int argc, char** argv)
{
    struct Person 
    {
        int age{};
        double weight{};
    };

    Person kunal;

    // Access using references
    Person& ref = kunal;
    ref.age = 25;
    std::cout << kunal.age << std::endl;

    // Access using pointers
    Person* const ptr = &kunal;
    std::cout << "Access using arrow operator - " << ptr->age << std::endl;
    std::cout << "Access using de-referencing - " << (*ptr).age << std::endl;
    

    struct Paw
    {
        int claws{};
    };

    struct Animal
    {
        std::string name{};
        Paw paw{};
    };

    Animal dog{ "Dog", { 5 } };
    Animal* ptr2 = &dog;

    std::cout << "Accessing non pointer using . " << ptr2->paw.claws << std::endl;

    return 0;
}
