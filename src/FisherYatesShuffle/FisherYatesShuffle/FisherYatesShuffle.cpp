#include <iostream>
#include <algorithm>
#include <iterator>
#include "generate_random.h"

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void fisher_yates_shuffle(int *arr, int arr_len)
{
    for (int i = arr_len - 1; i > 0; i--)
    {
        int rand_idx = generate_random(0, i);
        swap(arr[i], arr[rand_idx]);
    }
}

int main(int argc, char **argv)
{
    const int arr_len = 5;
    int arr[arr_len] = { 1, 2, 3, 4, 5 };
    int dest_arr[arr_len]{};

    // Copy original array
    std::copy(std::begin(arr), std::end(arr), std::begin(dest_arr));
    
    for (int i = 0; i < 16; i++)
    {
        fisher_yates_shuffle(dest_arr, arr_len);
        for (int j = 0; j < arr_len; j++)
        {
            std::cout << dest_arr[j] << " ";
        }
        std::cout << std::endl;
    }
}
