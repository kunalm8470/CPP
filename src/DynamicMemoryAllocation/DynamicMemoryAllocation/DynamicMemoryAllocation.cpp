#include <iostream>

void dynamic_allocate(int val)
{
	/*
		If the operating system hasn't enough memory
		then new operator may throw bad_alloc exception
		which can our program to crash if unhandled.

		// This is a safe way to handle the above situation
		// In this case if the new operator fails then a nullptr 
		// will be assigned instead
		
		int *value = new (std::nothrow) int;

		if (!value) {
			// Do error handling here
			std::cout << "Could not allocate memory";
		}
	*/
	int *ptr{ new int{val} };
	std::cout << "Value from heap: " << *ptr << std::endl;
	
	// Reclaim memory back to the operating system
	delete ptr;

	// Set ptr to nullptr to avoid dangling pointer issue
	ptr = nullptr;
}

void dynamic_allocate_array(size_t length)
{
	// Dynamically allocate memory from heap
	int *arr = new int[length]{};
	std::fill(arr, arr + 4, 5);

	for (const int* ptr = arr; ptr < (arr + length); ptr++)
	{
		std::cout << *ptr << std::endl;
	}

	// Reclaim memory back to the operating system
	// Using delete[] operator for arrays
	delete[] arr;

	// No need to set nullptr in case of arrays
}

int main(int argc, char **argv)
{
	dynamic_allocate(6);
	dynamic_allocate_array(4);

	return 0;
}
