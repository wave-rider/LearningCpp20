#include <iostream>
#include <vector>
#include <array>
#include <ctype.h>
using namespace std;

struct Foo {
    int   i;
    float f;
    char  c;
};

// Note: `alignas(alignof(long double))` below can be simplified to simply 
// `alignas(long double)` if desired.
struct alignas(alignof(long double)) Foo2 {
    // put your definition here
};

struct Empty {};

struct alignas(64) Empty64 {};
int main()
{
    std::cout << "Alignment of"  "\n"
        "- char             : " << alignof(char) << " sizeof:" << sizeof(char) << "\n"
        "- pointer          : " << alignof(int*) << " sizeof:" << sizeof(int*) << "\n"
        "- class Foo        : " << alignof(Foo) << " sizeof:" << sizeof(Foo) << "\n"
        "- class Foo2       : " << alignof(Foo2) << " sizeof:" << sizeof(Foo2) << "\n"
        "- empty class      : " << alignof(Empty) << " sizeof:" << sizeof(Empty) << "\n"
        "- alignas(64) Empty: " << alignof(Empty64) << " sizeof:" << sizeof(Empty64) << "\n";

    /*vector<int> v2(3);
    cout << v2[3];*/
    
    int* v = new int[] { 1, 2, 3 };
    cout << v[3];

    std::array myArray{ 9, 7, 5 };
    //cout << myArray[4];

   // const char∗ p = "Heraclitus";
   // const char∗ q = "Heraclitus";
    const char* p = "Heraclitus";
    const char* q = "Heraclitus";
    {
        if (p == q) cout << "one!\n"; // the result is implementation-defined
        // ...
    }
}