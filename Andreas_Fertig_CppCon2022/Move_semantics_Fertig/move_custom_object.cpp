#include <vector>
#include <iostream>
using namespace std;
struct Object{ 
Object() { cout << "ctor\n"; }
Object(const Object&) { cout << "copy ctor\n"; }
Object& operator=(const Object&) { cout << "copy assignment operator\n"; return *this; }
Object(Object&&) { cout << "move ctor\n"; }
Object& operator=(Object&&) { cout << "move assignment operator\n"; return *this; }
};

int main()
{
    vector<Object> v{};
    v.push_back(Object{});

    cout << "\nsecond element\n";
    v.push_back(Object{}); 

    cout << "\nthird element\n";
    v.push_back(Object{}); 

    cout << "\nforth element\n";
    v.push_back(Object{}); 
}

/*
ctor
move ctor

second element
ctor
move ctor
copy ctor -- this happens because the move constructor is not marked noexcept
*/