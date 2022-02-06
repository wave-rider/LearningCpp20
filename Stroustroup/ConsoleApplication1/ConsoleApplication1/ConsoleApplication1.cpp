// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void increment()
{
    int v[] = { 0,1,2,3,4,5,6,7,8,9 };
    for (auto x : v)
        ++x;
    // ...
    int x = 10;
    int& a = x;
    a = 3;
    std::cout << "Done " << x;
    std::vector<int> s{ 27};
    std::vector<int> pv(27);
    std::cout << "Vector Test";
    string name = "Niels Stroustrup";
    //string s = name.substr(6, 10); // s = "Stroustr up"
    name.replace(0, 5, "nicholas"); // name becomes "nicholas Stroustrup"
    name[0] = toupper(name[0]); // name becomes "Nicholas Stroustrup"    
    cout << name << endl;
    int b = 'b'; // note: char implicitly converted to int
    char c = 'c';
    cout << 'a' << b << c;
}

int main()
{
    std::cout << "Hello World!\n";
    increment();
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
