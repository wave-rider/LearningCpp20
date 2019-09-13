// Volatile.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <type_traits>
#include <stdio.h>
using namespace std; // to make cout working without std:: 

int main()
{
	volatile int clock = 0;
	cout << "volatile long clock = 0;" << endl;
	bool  result = is_volatile<decltype(clock)>::value; // is_volatile needs type_traits
	if (result)
	{
		cout << "clock is volatile" << endl << endl;
	}
	
	clock = 5;

	auto c = clock;
	cout << "auto c = clock;" << endl;

	result = is_volatile<decltype(c)>::value; // is_volatile needs type_traits
	if (!result)
	{
		std::cout << "c is not volatile" << endl;
	}

	// https://barrgroup.com/Embedded-Systems/How-To/C-Volatile-Keyword
}