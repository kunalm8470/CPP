#include <iostream>

int getSingleArrayIndex(int row, int col, int no_of_cols_per_row)
{
    return (row * no_of_cols_per_row) + col;
}

int main(int argc, char** argv)
{
    int value = 5;
    int* ptr = &value;
    int** ptr_to_ptr = &ptr;

    /*
        More than 1 level of
        indirection
    */
    std::cout << "Value= " << value << std::endl;
    std::cout << "Pointer value= " << (*ptr) << ", Pointer address= " << ptr << std::endl;
    std::cout << "Pointer to pointer value= " << (*(*ptr_to_ptr)) << ", Pointer address= " << *ptr_to_ptr << std::endl;

    /*
        Allocating a 2-D array
        from the heap using the 
        new operator

        Iterate over the rows,
        and allocate for each row

        Multi-dimensional arrays in
        C++ are stored in a row-major
        order in memory
    */
    int** arr = new int*[10];
    for (int i = 0; i < 10; i++) 
    {
        arr[i] = new int[5];
    }

    /*
        Multiple ways of
        accessing the same index
    */
    arr[9][3] = 5;
    (arr[9])[4] = 5;
    

    /*
        Deallocating the above
        2-D array using delete
        operator

        Iterate over the rows,
        and de-allocate for each row
    */
    for (int i = 0; i < 5; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    /*
        Instead of allocating a
        nested array, we can flatten the
        above using a simple 1-D and
        pointer arithmetic
    */
    int* arr2 = new int[50];
    arr2[getSingleArrayIndex(9, 4, 5)] = 5;

    return 0;
}
