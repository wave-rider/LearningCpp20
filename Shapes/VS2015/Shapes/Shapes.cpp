// Shapes.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Shape.hpp"
#include <vector>

void rotate_all(std::vector<Shape*>& v, int angle) // rotate v’s elements by angle degrees
{
	for (auto p : v)
		p->rotate(angle);
}

int main()
{
    return 0;
}

