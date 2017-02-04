//
//  main.cpp
//  CppTestApp
//
//  Created by admin on 2/3/17.
//  Copyright © 2017 admin. All rights reserved.
//

#include <iostream>
#include "MySecondClass.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    cout << "Hello, World!\n";
    MyClass c;
    MyClass m;
    c.x = 10;
    cout << c.x << endl;
    
    MySecondClass d;
    d.ShowMyClass(&c);
    
    MyClass& f = c;
    f.x=20;
    f = m; // In the debug build this line will produce an error in VS 2015
    cout << "MyClass:f!\n" << f.x;
	char a;
	cin >> a;
    return 0;
}
