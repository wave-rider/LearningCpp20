// Strings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include "Utils.h"
// The good test for the sharp symbol
using namespace std;

string ident(string arg) // string passed by value (copied into arg)
{
	return arg; // return string (move the value of arg out of ident() to a caller)
}

int _tmain(int argc, _TCHAR* argv[])
{
	string s1{ "Adams" }; // initialize str ing (constr uct in s1).
	s1 = Utils::ident(s1); // copy s1 into ident()
	// move the result of ident(s1) into s1;
	// s1’s value is "Adams".
	string s2{ "Pratchett" }; // initialize str ing (constr uct in s2)
	s1 = s2; // copy the value of s2 into s1
	// both s1 and s2 have the value "Pratchett".
	s1 = "Hello";
	cout << "s2 value:" << s2;
	cout << "s1 value:" << s1;

	return 0;
}


