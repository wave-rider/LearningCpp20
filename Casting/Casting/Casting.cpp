// Casting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class A
{
public:
    virtual int getNumber() { return 42; } // The result of main will be -1 if this method is virtual
};
class B : public A
{
public:
    int getNumber() { return -1; }
};

int main()
{

    B b;
    A* p = &b;
    int j = p->getNumber();
    cout << "j=" << j;
}


