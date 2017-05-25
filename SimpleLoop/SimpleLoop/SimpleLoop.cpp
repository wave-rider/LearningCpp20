// SimpleLoop.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	//int a = 5;
	//a = cout << "good" + cout << "boy";
	int (*p)[100];
	int q[100];
	p = &q;
	++p;
	time_t now = time(0);
	srand(now);
	cout << rand();
	return 0;
}
