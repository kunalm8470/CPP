#include <iostream>
#include <iterator>

void foo(int x)
{
    std::cout << x << std::endl;
}

int bar(int x)
{
    return x -= 1;
}

/*
	Keeping the function
	definitions in main.cpp
	until we learn about templates
	later
*/
template<typename T>
bool ascending_comparer(T x, T y)
{
	return x > y;
}

template<typename T>
bool descending_comparer(T x, T y)
{
	return x < y;
}

template<typename T, size_t N>
void selection_sort(T(&arr)[N], bool (*comparer_func)(T, T))
{
	for (size_t i = 0; i < N - 1; i++)
	{
		size_t smallest = i;
		for (size_t j = i + 1; j < N; j++)
		{
			if ((*comparer_func)(arr[smallest], arr[j]))
			{
				smallest = j;
			}
		}

		if (smallest != i)
		{
			std::swap<T>(arr[i], arr[smallest]);
		}
	}
}

template<typename T, size_t N>
void print_array(const T(&arr)[N])
{
	for (const auto& item : arr)
	{
		std::cout << item << " ";
	}
	std::cout << std::endl;
}


int main(int argc, char** argv)
{
    std::cout << "Address of foo= " << foo << std::endl;

    /*
        C++ will try to
        implicitly convert a function
        to a function pointer without the
        address-of-operator (&) also
    */
    int (*fncPtr)(int) = &bar;

    // Implicitly de-referencing
    // Older compilers might not support this completely
    std::cout << "Calling function bar using function reference: " << fncPtr(5) << std::endl;

    // Explicitly de-referencing
    std::cout << "Another way of calling function bar using function reference: " << (*fncPtr)(6) << std::endl;

    int arr[] = { 5, 4, 3, 2, 1, 0, -1 };
    constexpr size_t len = std::size(arr);

    selection_sort<int, len>(arr, ascending_comparer);
    print_array<int, len>(arr);

    return 0;
}
