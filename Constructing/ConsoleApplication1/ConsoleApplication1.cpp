// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ConstructorInitializer.h"

int _tmain(int argc, _TCHAR* argv[])
{
	ConstructorInitializer a{};
	ConstructorInitializer b{ 1 };
	ConstructorInitializer c( 2 );
	ConstructorInitializer d{ 2, 0, 1, 7 };


	return 0;
}

