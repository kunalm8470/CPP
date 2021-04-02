#include <iostream>
#include <iterator>

enum class StudentNames
{
    kenny = 0, // 0
    kyle = 1, // 1
    stan = 2, // 2
    butters = 3, // 3
    cartman = 4, // 4
    wendy = 5, // 5
    max_students = 6 // 6
};

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void selection_sort(int arr[], int arr_len) {
    for (int i = 0; i < arr_len; i++) {
        int smallest = i;

        for (int j = i; j < arr_len; j++) {
            if (arr[j] < arr[smallest]) {
                smallest = j;
            }
        }

        swap(arr[i], arr[smallest]);
    }
}


/*
    When sizeof is used on an array that has been passed to a function, 
    it doesn't error out like std::size() does.
    Instead, it returns the size of a pointer.
*/
void print_size(int arr[]) 
{
    std::cout << sizeof(arr) / sizeof(int) << std::endl;
}

int main()
{
    int prime[5]{}; // hold the first 5 prime numbers
    prime[0] = 2; // The first element has index 0
    prime[1] = 3;
    prime[2] = 5;
    prime[3] = 7;
    prime[4] = 11; // The last element has index 4 (array length-1)

    std::cout << "The sum of the first 5 primes is: " << prime[0] + prime[1] + prime[2] + prime[3] + prime[4] << '\n';

    int arr[5]{};

    // using a literal (constant) index:
    arr[1] = 7; // ok

    // using an enum (constant) index
    enum Animals
    {
        animal_cat = 2
    };
    arr[Animals::animal_cat] = 4; // ok

    // using a variable (non-constant) index:
    short index = 3;
    arr[index] = 7; // ok

    // using an expression that evaluates to an integer index:
    arr[1 + 2] = 7; // ok

    // Array intializer list
    int prime2[5]{ 2, 3, 5, 7, 11 };

    int testScores[static_cast<int>(StudentNames::max_students)]{}; // allocate 6 integers
    testScores[static_cast<int>(StudentNames::stan)] = 76;

    /* 
        Using std::size gives us the size of the array
        std::size was introduced in C++ 17
    */
    std::cout << std::size(testScores) << std::endl;

    /*
        For versions lesser than C++ 17, use sizeof keyword
    */
    int array[]{ 1, 1, 2, 3, 5, 8, 13, 21 };
    std::cout << sizeof(array)/sizeof(array[0]) << '\n';
    print_size(array);

    // Sorting array using selection sort
    int ar[]{ 30, 50, 20, 10, 40 };
    int ar_len = sizeof(ar) / sizeof(int);

    selection_sort(ar, ar_len);

    for (const int item : ar) {
        std::cout << item << std::endl;
    }

    // 2-D array intializer list
    int multi_dimensional_array[3][5]
    {
      { 1, 2, 3, 4, 5 }, // row 0
      { 6, 7, 8, 9, 10 }, // row 1
      { 11, 12, 13, 14, 15 } // row 2
    };

    // Iterate over a 2-D array
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << multi_dimensional_array[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    return 0;
}
