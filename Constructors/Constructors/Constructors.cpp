// Constructors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <string>
using namespace std;
class Person
{
public:
	int age;
	string name;
	Person(int age) : age{ age } { };	
};

struct Animal
{
public:
	int number_of_legs;
};

int main()
{
	Person test{8};
	Animal animal{};
	return 0;
}

