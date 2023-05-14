// Explicit_Sololearn.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class C
{
public:
    int v{ 10 };
    explicit C(int _v): v{_v}
    {
        cout << "i";
    }
    C(double)
    {
        cout << "d";
    }

   /* This is generated automatically in c++ 11
   C& operator=(C& other)
    {
        v = other.v;
        return *this;
    }*/
};

int main()
{
    C c1(7);//i
    C c2 = 7; //d
    C c3(6);// i
    c2 = c3;
    cout << "\n" << c2.v << "\n"; //6

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
