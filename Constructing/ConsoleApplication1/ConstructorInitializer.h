#pragma once
#include <initializer_list>

struct ConstructorInitializer
{
public:
	ConstructorInitializer();
	ConstructorInitializer(std::initializer_list<int>);
	ConstructorInitializer(int);
	virtual ~ConstructorInitializer();
private:
	int intValue;
};

