// VirtualDestructor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class Shape {
public:
	virtual void draw() = 0;
	virtual ~Shape() { 
		std::cout << "Shape destructor is called" << std::endl; 
	} 
};

class Circle : public Shape {
public:
	void draw() {}
	~Circle() { 
		std::cout << "Circle destructor is called" << std::endl;
	}
};

int main()
{
	Shape* shape = new Circle();
	delete shape;
    return 0;
}

