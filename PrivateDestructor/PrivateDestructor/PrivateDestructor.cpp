// PrivateDestructor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
//http://www.geeksforgeeks.org/private-destructor/

using namespace std;

class PrivateDestructorClass {
public:
	void destroy() { 
		delete this; 
	}
private:
	~PrivateDestructorClass() {
		cout << "Oject is destructed";
	} 
};

int main()
{
	PrivateDestructorClass* pr = new PrivateDestructorClass;
	pr->destroy();
	return 0;
}

