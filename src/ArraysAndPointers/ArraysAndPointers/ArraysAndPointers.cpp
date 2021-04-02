#include <iostream>
#include <cstring>

void print_size(int arr[]) 
{
	// Fixed arrays decay into pointers internally in C++
	std::cout << sizeof(arr) << std::endl;
}

void mutate_array(int* arr)
{
	arr[0] = 5;
}

bool isVowel(char ch)
{
	switch (ch)
	{
		case 'A':
		case 'a':
		case 'E':
		case 'e':
		case 'I':
		case 'i':
		case 'O':
		case 'o':
		case 'U':
		case 'u':
			return true;
		default:
			return false;
	}
}

int* find(int *begin, int *end, int search_item)
{
	for (int *i = begin; i != end; i++) 
	{
		if (*i == search_item)
		{
			return i;
		}
	}

	return end;
}

int main(int argc, char** argv)
{
	int i_arr[5]{ 9, 7, 5, 3, 1 };

	/*
		Prints the sizeof of the pointer
		not the actual array
	*/
	print_size(i_arr);

	/*
		Arrays are passed by address,
		because copying large arrays using pass-by-value is slow
		hence mutating the parameter in the function mutates
		the original array
	*/
	mutate_array(i_arr);

	std::cout << "Starting address: " << i_arr << std::endl;

	/*
		Scaling - When calculating the result of a pointer arithmetic expression,
		the compiler always multiplies the integer operand by the size of the object being pointed to.
		doing i_arr + 1 returns address of next item that it points to
		(i_arr + 1) means moving by 4 bytes in x86
	*/
	std::cout << "Starting value: " << *(i_arr) << std::endl;
	std::cout << "Next value: " << *(i_arr + 1) << std::endl;
	std::cout << "Last value: " << *(i_arr + 4) << std::endl;

	std::cout << "Iterating over the array using pointer indexing" << std::endl;
	for (int* ptr_index = i_arr; ptr_index < i_arr + 5; ptr_index++)
	{
		std::cout << *ptr_index << std::endl;
	}

	// Arrays are laid out sequentially in memory
	std::cout << "Starting address: " << &i_arr[0] << std::endl;
	std::cout << "Next address: " << &i_arr[1] << std::endl;
	std::cout << "Next address: " << &i_arr[2] << std::endl;
	std::cout << "Next address: " << &i_arr[3] << std::endl;
	std::cout << "Last address: " << &i_arr[4] << std::endl;

	const char *name = "Kunal";
	size_t name_length = strlen(name);
	int no_vowels = 0;

	for (const char *ptr = name; ptr < (name + name_length); ptr++)
	{
		if (isVowel(*ptr))
		{
			no_vowels++;
		}
	}

	std::cout << name << " has " << no_vowels << " vowels.\n";

	int arr[]{ 2, 5, 4, 10, 8, 20, 16, 40 };
	const int *found = find(std::begin(arr), std::end(arr), 20);

	if (found == std::end(arr))
	{
		std::cout << "Element " << 20 << " not found!";
	}
	else 
	{
		std::cout << "Element " << 20 << " found at address: " << found;
	}

	return 0;
}
