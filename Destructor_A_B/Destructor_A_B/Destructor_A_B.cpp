// Destructor_A_B.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
using namespace std;
class A
{
protected:
	int randomId;
public:
	A()
	{
		randomId = rand();
		cout << "Constructor for a class A with Id:" << randomId << endl;
	}
	virtual ~A()
	{
		cout << "Destructor for a class A with Id:" << randomId << endl;
	}
};

class B : public A
{
public:
	B()
	{
		cout << "Constructor for a class B with Id:" << randomId << endl;
	}
	~B()
	{
		cout << "Destructor for a class B with Id:" << randomId << endl;
	}
};


int main()
{
	srand((unsigned)time(NULL));
	cout << "Creating an object of the class B on the stack --->" << endl;
	auto pB = new B();
	unique_ptr<A> b(std::move(pB));
	cout << "The object of the class B is created --->" << endl;
	
	cout << "Creating an object of the class A on the stack --->" << endl;
	auto a = make_unique<A>();
	cout << "The object of the class A is created --->" << endl;
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
