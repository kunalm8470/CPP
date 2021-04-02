#include <iostream>
#include <string>

class DateClass
{
    /*
        Class members are implicitly
        default private without marking
        explicitly with the keyword
    */
    private:
        int m_year{};
        int m_month{};
        int m_day{};

    public:
        /*
            Equivalent to empty
            constructor body only
            difference being that
            it safely initializes all
            member variables with default values
        */
        DateClass() = default;

        DateClass(int year, int month, int day)
        {
            m_year = year;
            m_month = month;
            m_day = day;
        }

        int get_year()
        {
            return m_year;
        }

        void set_year(int year)
        {
            m_year = year;
        }

        int get_month()
        {
            return m_month;
        }

        void set_month(int month)
        {
            m_month = month;
        }

        int get_day()
        {
            return m_day;
        }

        void set_day(int day)
        {
            m_day = day;
        }
        
        void to_string() const
        {
            /*
                Member functions implicitly
                have reference to the member variables

                But in regular functions you need to pass
                the arguments as parameters to the function
            */
            std::cout << m_day << '-' << m_month << '-' << m_year << std::endl;
        }
}; // Semi-colon needed here, older compilers pre 2010 wont detect this

class A
{
    private:
        /*
            Since C++11 its possible to initialize
            member variables directly
        */
        int m_x = 4;
    public:
        A()
        {
            std::cout << "A default constructor called!" << std::endl;
        }

        A(int x)
        {
            m_x = x;
        }
};

class A1
{
    private:
        int m_x1 = 5;
    public:
        A1()
        {
            std::cout << "A1 default constructor called!" << std::endl;
        }

        A1(int x1)
        {
            m_x1 = x1;
        }
};

class B
{
    private:
        A m_a;
        A1 m_a1;
    public:
        B()
        {
            std::cout << "B default constructor called!" << std::endl;
        }

        B(int x) : 
            m_a{ x },
            m_a1{ x }
        {
        }
};

class Student
{
    private:
        std::string m_name;
        size_t m_score;
    public:
        Student()
        {
            m_name = "John Doe";
            m_score = 0;
        }

        Student(const std::string& name, int score)
        {
            m_name = name;
            m_score = score;
        }

        /*
            Delegating constructors to reduce
            boilerplate code from getting repeated
        */
        Student(const std::string& name) : Student(name, 0) {}

        explicit Student(int score): Student("John Doe", score) {}
        /*
            To prevent implicit conversion
            of self promoting types in the
            constructor mark it explicit
            and also delete the constructor
            with self-promoting types
        */
        //Student(char) = delete;  
};

int main(int argc, char** argv)
{
    // d1 is allocated from the stack
    DateClass d1;
    
    /*
        Accessing members
        using the member selection operator
    */
    d1.set_year(2020);
    d1.set_month(9);
    d1.set_day(20);

    d1.to_string();

    /*
        Another way to set
        private members is to
        use parameterized constructors
        also known as direct initializers
    */
    DateClass d2(2020, 9, 20);

    /*
        Before the outer class constructor
        is executed all the member variables 
        will be initialized first which in result
        calls the constructor of the member variables(if any)
        in order
    */
    B b;
    B b1(2); // Constructor gets initialized using the intializer list specified

    /*
        Brace initialization of constructor
        This is not preferred as it causes
        self promoting types to promote themselves
        like char to int causing a side-effect
    */
    Student kunal{ "Kunal Mukherjee", 25 }; // Calls Student(const std::string&, int);
    Student s1{ "Jane Doe" }; // Calls Student(const std::string&);
    Student s2{ 40 }; // Calls Student(int);
    Student s3{ 'a' }; // Promotion of self promoting types, a side-effect

    return 0;
}
