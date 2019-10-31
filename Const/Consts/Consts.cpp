// Consts.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Printer.h"

void my_function(Printer const& p)
{
	std::cout << endl << "my_function is called..." << endl;
	// p.x = 7; This will not work if a function declared as " void my_function(Printer& p) "
	// p.set_x(7); This will also not work and show the compiler error
	std::cout << "Get p.x => " << p.x << endl;
}

int main()
{
	/*
	https://stackoverflow.com/questions/1143262/what-is-the-difference-between-const-int-const-int-const-and-int-const#
Read it backwards (as driven by Clockwise/Spiral Rule):
int* - pointer to int
int const * - pointer to const int
int * const - const pointer to int
int const * const - const pointer to const int
	*/
	const int int_const1 = 3;
	const int int_const2 = 4;

	// int* my_pointer = &int_const1; doesn't work
	const int * my_pointer = &int_const1;
	my_pointer = &int_const2;

	Printer* printer = new Printer();
	printer->print();
	printer->set_x(15);
	my_function(*printer);

	int const my_const = 12;
	std::cout << endl << "after my_function was called the x is " << printer->get_x();
	
	int b = 8;
	int* const a = &(printer->x); // It is a const pointer to int
	// a = &b; this is not possible as we cannot change the constant pointer
	// https://www.geeksforgeeks.org/difference-between-const-int-const-int-const-and-int-const/

	//int const* p = 5; this will not compile
	//cout << ++(*p);
	return 0;
}

