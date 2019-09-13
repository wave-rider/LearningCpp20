// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ConstructorInitializer.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "ConstructorInitializer a{};" << endl;
	ConstructorInitializer a{};
	cout << endl;

	cout << "ConstructorInitializer b{ 1 };" << endl;
	ConstructorInitializer b{ 1 };
	cout << endl;

	cout << "ConstructorInitializer c(6);" << endl;
	ConstructorInitializer c( 2 );
	cout << endl;

	cout << "ConstructorInitializer d{ 2, 0, 1, 9 };" << endl;
	ConstructorInitializer d{ 2, 0, 1, 9 };


	return 0;
}

