// Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctype.h>
#include <string>
#include "Pointers.h"
#include <initializer_list>

using namespace std;

class MyClass {
public:
    int GetA() {
        return a;
    }
    int a;
    int b;

private:
    MyClass(int a, int inputB) : a(++a), b(inputB)
    {

    }


};

class MyClass2
{
public:
    MyClass2(float f, char a);
private:
    float mFloat;
    char mCharacter;
    bool mBoolean;
    int mInteger;
};

MyClass2::MyClass2(float f, char a) : mFloat(f), mBoolean(true) // option 1.
{
    // option 2
    mCharacter = a;
    mInteger = 0;
}

class Box2
{
public:
    Box2() = delete;
    Box2(const Box2& other) = default;
    Box2& operator=(const Box2& other) = default;
    Box2(Box2&& other) = default;
    Box2& operator=(Box2&& other) = default;
    Box2(initializer_list<string> list, int, int h, int l);
    //...
};

//Box2::Box2(initializer_list<string> list, int w = 0, int h = 0, int l = 0)
//    : m_contents(list), m_width(w), m_height(h), m_length(l)
//{}

//class ShippingOrder
//{
//public:
//    ShippingOrder(Box b, double postage) : m_box(b), m_postage(postage) {}
//
//private:
//    Box m_box;
//    double m_postage;
//}
////elsewhere...
//ShippingOrder so(42, 10.8);

void func(char* p)
{
    char* const cp = p; // const pointer to char
    char const* pc; //pointer to const char
    const char* pc2; //pointer to const char

    char s[] = "Gorm";
    char const* cp2 = s; // constant pointer
    cp[3] = 'a'; // OK
}

int main()
{
    std::cout << "Hello World!\n";
    char s[] = "Gorm";
    const char* pc = s; // pointer to constant
    //pc[3] = 'g'; // error : pc points to constant
    pc = s; // OK
    char *const cp = s; // constant pointer
    char const* cp2 = s; // constant pointer
    cp[3] = 'a'; // OK
    
    //cp = s; // error : cp is constant
    const char *const cpc = s; // const pointer to const
    //cpc[3] = 'a'; // error : cpc points to constant
    //cpc = s; // error : cpc is constant
    func(s);

 /*   MyClass* classA = new MyClass(7, 8);
    std::cout << classA->GetA();*/
    int aa[10];
    aa[6] = 9; // assign to aa’s 7th element
    int x = aa[99]; // undefined behavior
    cout << x;
    cout << "sizeof(\"Bohr\")" << sizeof("Bohr") << "strlen(\"Bohr\"):" << strlen("Bohr");

    //char∗ p = "Plato"; // error, but accepted in pre-C++11-standard code
    //p[4] = 'e'; // error : assignment to const

    char m[] = "Zeno"; // p is an array of 5 char
    m[0] = 'R'; // OK

    const char* p = "Heraclitus";
    const char* q = "Heraclitus";
    
    if (p == q) cout << "one!\n"; // the result is implementation-defined
    else std::cout << "Another one!\n";
    
    char alpha[] = "abcdefghijklmnopqrstuvwxyz\n"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    std::cout << alpha;
}

