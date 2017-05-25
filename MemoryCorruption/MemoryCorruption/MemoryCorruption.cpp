// MemoryCorruption.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	//char  *inputName = new char; //Wrong
	char  *inputName = new char[2];//Correct if an input is one character
	cin >> inputName;
	delete inputName;
    return 0;
}

