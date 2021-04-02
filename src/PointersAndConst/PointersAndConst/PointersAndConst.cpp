#include <iostream>

int main(int argc, char **argv)
{
	/*
		const integer
	*/
	const int a = 4;

	/*
		Both int const* and const int*
		are similar and point to the same memory

		Both are pointers to a const int
	*/
	int const* ptr1 = &a;
	const int* ptr2 = &a;

	/*
		Both the pointer the value
		its referring to can't be changed
	*/
	const int* const ptr3 = &a;

	std::cout << "Address of a= " << &a << std::endl;
	std::cout << "Address of ptr1= " << ptr1 << std::endl;
	std::cout << "Address of ptr2= " << ptr2 << std::endl;
	std::cout << "Address of ptr3= " << ptr3 << std::endl;

	/*
		Mutable integer
	*/
	int b = 4;

	/*
		Constant pointer to a
		mutable integer
	*/
	int* const ptr4 = &b;
	std::cout << "Address of b= " << &b << std::endl;
	std::cout << "Address of constant pointer ptr3= " << ptr4 << std::endl;
	
	/*
		'a' now can't be changed
		using ref1
	*/
	const int& ref1 = a;
	std::cout << "Reference of a= " << ref1 << std::endl;

	return 0;
}
