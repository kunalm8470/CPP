#include <iostream>
#include <bitset>
#include <string>
#include <algorithm>

std::string dec_to_binary(unsigned x)
{
	std::string s;
	do
	{
		/*
			'0' -> 48 in ASCII
			(x & 1) bitmask will produce 0 if bit is 0, else the bit
			effectively adding it up
		*/
		s.push_back('0' + (x & 1));
	} while (x >>= 1);
	std::reverse(s.begin(), s.end());
	return s;
}

int countNumOfOnes(int n)
{
	int counter = 0;
	while (n) {
		if (n & 1) {
			counter += 1;
		}

		n >>= 1;
	}
	return counter;
}

std::bitset<4> rotl(std::bitset<4> bits)
{
	bool flag = bits.test(3);

	bits <<= 1;

	if (flag) {
		bits.set(0);
	}

	return bits;
}

bool isUpperCase(char c)
{
	/*	
		0b00100000 is the bit mask here
		if we bitwise AND the bitmask with the test_num we get 0

	*/
	return (c & 0b00100000) == 0;
}

int main(char** argv, int argc) 
{
	// Is represented in 8 bits like - 0000 0101
	std::bitset<8> bits("0101");
	
	// Sets it to 1 if 0, if 1 does nothing
	bits.set(3);
	
	/* 
		Toggles between the value, if 0 set to 1 and vice-versa
	*/
	bits.flip(4);

	// Explicitly sets the bit to 0
	bits.reset(4);

	/*
		Methods set, flip, reset only modify a single bit
	*/
	std::cout << "All the bits: " << bits << '\n';
	std::cout << "Bit 3 has value: " << bits.test(3) << '\n';
	std::cout << "Bit 4 has value: " << bits.test(4) << '\n';

	/*
		To shift multiple bits in a single-go, use the bitwise operators
	*/
	std::bitset<4> x("1100");

	// shift right by 1, yielding 0110
	std::cout << "Right shifted: " << (x >> 1) << '\n';

	// shift left by 1, yielding 1000
	std::cout << "Left shifted: " << (x << 1) << '\n';

	// Bitwise not (~) flips all the bits
	std::cout << "All flipped: " << (~x) << '\n';
	
	//***-----------***-----------***
	std::bitset<8> a("0101");
	std::bitset<8> b("0110");
	/* 
		Bitwise OR works similar to logical OR
		bitwise OR applies to each bit from R->L

		Rules -
		If both bits are 1, then 1
		If any of the bits is 1, then 1
		If both bits are 0, then 0
		
		0101
		0110
		____
		0111
	*/
	
	std::cout << "Bitwise OR: " << (a | b) << '\n';

	/*
		Bitwise AND works similar to logical AND
		bitwise AND applies to each bit from R->L

		Rules -
		If both bits are 1, then 1
		If any of the bits is 0, then 0
		If both bits are 0, then 0

		0101
		0110
		____
		0100
	*/

	std::cout << "Bitwise AND: " << (a & b) << '\n';

	/*
		Bitwise XOR

		Rules -
		If both bits are 1, then 0
		If any of the bits is 0, then 1
		If both bits are 0, then 0

		0101
		0110
		____
		0011
	*/

	std::cout << "Bitwise XOR: " << (a ^ b) << '\n';
	
	/*
		We can assign and do bitwise operation in a single statement
		x <<= y	(Shift x left by y bits)
		x >>= y	(Shift x right by y bits)
		x |= y	(Assign x | y to x)
		x &= y	(Assign x & y to x)
		x ^= y	(Assign x ^ y to x)
	*/

	std::bitset<4> y("0100");
	y >>= 1;
	std::cout << "Bitwise assignment: " << y << '\n';
	

	std::bitset<4> bits1("0001");
	std::cout << "ROTL 1: " << rotl(bits1) << '\n';

	std::bitset<4> bits2("1001");
	std::cout << "ROTL 2: " << rotl(bits2) << '\n';

	//***-----------***-----------***
	std::cout << "Testing 'a' if uppercase: " << static_cast<bool>(isUpperCase('a')) << '\n';
	std::cout << "Testing 'A' if uppercase: " << static_cast<bool>(isUpperCase('A')) << '\n';

	// Define a bunch of physical/emotional states
	std::bitset<8> isHungry{ 0b0000'0001 };
	std::bitset<8> isSad{ 0b0000'0010 };
	std::bitset<8> isMad{ 0b0000'0100 };
	std::bitset<8> isHappy{ 0b0000'1000 };
	std::bitset<8> isLaughing{ 0b0001'0000 };
	std::bitset<8> isAsleep{ 0b0010'0000 };
	std::bitset<8> isDead{ 0b0100'0000 };
	std::bitset<8> isCrying{ 0b1000'0000 };


	std::bitset<8> me{}; // all flags/options turned off to start
	me |= isHappy | isLaughing; // I am happy and laughing
	me &= ~isLaughing; // I am no longer laughing

	// Query a few states (we use the any() function to see if any bits remain set)
	std::cout << "I am happy? " << (me & isHappy).any() << '\n';
	std::cout << "I am laughing? " << (me & isLaughing).any() << '\n';


	/*
		Summarizing how to set, clear, toggle, and query bit flags:

		To query bit states, we use bitwise AND:
		if (flags & option4) ... // if option4 is set, do something

		To set bits (turn on), we use bitwise OR:
		flags |= option4; // turn option 4 on.
		flags |= (option4 | option5); // turn options 4 and 5 on.
		
		To clear bits (turn off), we use bitwise AND with bitwise NOT:
		flags &= ~option4; // turn option 4 off
		flags &= ~(option4 | option5); // turn options 4 and 5 off

		To flip bit states, we use bitwise XOR:
		flags ^= option4; // flip option4 from on to off, or vice versa
		flags ^= (option4 | option5); // flip options 4 and 5
	*/

	int counter = countNumOfOnes(9);
	int dec_value = 32;
	std::string binary_rep = dec_to_binary(dec_value);
	return 0;
}