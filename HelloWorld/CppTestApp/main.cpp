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
	Picachu* cPicaPointer = new Picachu("cPicaPointer", 1);
	const Picachu& cPicaReference = Picachu("cPicaReference", 2);
	MyClass c(cPicaReference, cPicaPointer);
	
	Picachu* mPicaPointer = new Picachu("mPicaPointer", 3);
	const Picachu& mPicaReference = Picachu("mPicaReference", 4);
	MyClass m(mPicaReference, mPicaPointer);
	
	c.x = 10;
	m.x = 15;
    cout << "c.x=" << c.x << endl;
	cout << "m.x" << m.x << endl;

    
    MySecondClass d;
    d.ShowMyClass(&c);
    
    MyClass& f = c;
	cout << "1) c.x=" << c.x << endl;
    f.x=20;
	cout << "2) c.x=" << c.x << endl;
    //f = m; // In the debug build this line will produce an error in VS 2015
	// Re-binding reference doesn't make sense.
	cout << "3) c.x=" << c.x << endl;
	c.x = 58;
	cout << "4) c.x=" << c.x << endl;
	cout << "5) f.x=" << f.x << endl;
	cout << "6) m.x=" << m.x << endl;

	m.x = 33;
	cout << "7) c.x=" << c.x << endl;
	cout << "8) f.x=" << f.x << endl;
	cout << "9) m.x=" << m.x << endl;


	// http://www.embedded.com/electronics-blogs/programming-pointers/4023307/References-vs-Pointers
    char a;
	cin >> a;

    return 0;
}
