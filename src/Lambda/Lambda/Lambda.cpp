#include <iostream>
#include <algorithm>
#include <iterator>
#include <functional>
#include <string>
#include <vector>

struct Student
{
    std::string name {};
    int score;
};

template<typename T, size_t N>
void sort_asc(T (&arr)[N])
{
    /*
        Lambda are not functions but they are 
        functors (callable objects) by overloading
        the parenthesis operator

        Capture clause here is set to reference

        Capture mode can be of 3 types -
        1. [&] means captured variables are by-reference, 
        changes will affect variables from outside the body

        2. [=] means captured variables are by-value, 
        changes to them in the body will not affect 
        the value outside the body

        3. [] means no capture of variables from 
        other scope(s)
    */
    std::sort(std::begin(arr), std::end(arr), [&](T a, T b) -> bool {
        return a < b;
    });
}

template<typename T, size_t N>
void sort_desc(T(&arr)[N])
{
    std::sort(std::begin(arr), std::end(arr), [&](T a, T b) -> bool {
        return a > b;
    });
}

void fill_vector(std::vector<int>& v)
{
    static int seed = 1;

    /*
        Static variables don't need capturing
        because they have static storage duration

        We can simply use it in lambda

        We can only capture variables having
        automatic storage duration and this
    */
    std::generate(v.begin(), v.end(), []() -> int {
        return seed++;
    });
}

int main(int argc, char** argv)
{
    int arr[] = { 5, 7, 4, 2, 8, 6, 1, 9, 0, 3 };
    double arr2[] = { 5.3, 7.65, 4.21, 2.98, 8.01, 6.24, 1.05, 9.03, 0.5, 3.07 };

    sort_asc<int, std::size(arr)>(arr);
    sort_desc<double, std::size(arr2)>(arr2);

    std::function<double(double, double)> add_numbers = [=](double a, double b) -> double {
        return a + b;
    };
    std::cout << "Captured lambda used as a function literal= " << add_numbers(1, 2) << std::endl;

    Student students[] = {
        { "Albert", 3 },
        { "Ben", 5 },
        { "Christine", 2 },
        { "Dan", 8 },
        { "Enchilada", 4 },
        { "Francis", 1 },
        { "Greg", 3 },
        { "Hagrid", 5 }
    };

    Student* max_student_score = std::max_element(std::begin(students), std::end(students), [&](const Student& a, const Student& b) -> bool {
        return a.score < b.score;
    });
    std::cout << "Max score is= " << max_student_score->score << std::endl;

    int counter = 3;
    /*
        Lambda return type can be inferred
        in C++14 and above

        The mutable modifier must be passed after the
        parameter list and indicates the captured value is mutable

        Everything else is captured by reference
    */
    auto count_down = [&, counter]() mutable -> void {
        std::cout << "Counting down in= " << counter << std::endl;
        counter -= 1;
    };
    
    count_down();
    count_down();
    count_down();

    int x = 4;
    double y = 3.14159;

    /*
      Selectively only capturing x, y and students
      from the above scope

      x and y are captured by value
      and students is captured by reference
    */
    auto print_everything = [x, y, &students]() -> void {
        std::cout << "x= " << x << std::endl;
        std::cout << "y= " << x << std::endl;
        
        std::cout << "Displaying student data" << std::endl;
        for (const Student& current_student : students)
        {
            std::cout << "Name= " << current_student.name << std::endl;
        }
    };

    print_everything();

    std::vector<int> vec(5);
    fill_vector(vec);

    return 0;
}
