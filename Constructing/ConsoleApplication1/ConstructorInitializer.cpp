#include "stdafx.h"

#include <initializer_list>
#include <iostream>
#include "ConstructorInitializer.h"

ConstructorInitializer::ConstructorInitializer(std::initializer_list<int> initList){
	std::cout << "Std:initializer_list constructor " << std::endl;

	std::cout << "Passed values:" << std::endl;
	for (auto i : initList){
		std::cout << i << " ";
		intValue = i;
	}

	std::cout << std::endl;
}

ConstructorInitializer::ConstructorInitializer(){
	intValue = -1;
	std::cout << "This is a default constructor with no parameters intValue="<< intValue << std::endl;
}

/* Don't do this in C++
ConstructorInitializer::ConstructorInitializer(int passedValue) {
	intValue = passedValue;
	std::cout << "This is a constructor with one parameter" << std::endl;
}
*/

ConstructorInitializer::ConstructorInitializer(int passedValue) : intValue{passedValue}{
	std::cout << "This is a constructor with one parameter intValue=" << intValue << std::endl;
}

ConstructorInitializer::~ConstructorInitializer()
{
	std::cout << "Destructor is called with int value:" << intValue << std::endl;
}
