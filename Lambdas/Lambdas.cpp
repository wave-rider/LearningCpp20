// Lambdas.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <functional>
#include <memory>
#include <algorithm>
#include <type_traits>
#include <fstream>

using namespace std;

function<bool()> f()
{
	auto a = 5;
	auto b = -3;
	// won't compile if a & b aren't captured
	return [=]() { return a + b > 0; };
}

class LambdaStore
{
	function<bool(double)> _stored_lambda;
public:
	function<int(int)> get_abs() const
	{
		return [](int i) { return abs(i); };
	}

	void set_lambda(const function<bool(double)>& lambda)
	{
		_stored_lambda = lambda;
	}

	bool call_lambda(double x)
	{
		return _stored_lambda(x);
	}
};



int main()
{
	LambdaStore ls;

	ls.set_lambda([](double d) { return d > 0.0; });
	ls.call_lambda(12);
	auto abs_lambda = ls.get_abs();
	abs_lambda(-10);   // returns 10

	if (abs_lambda(-10) != 10)
	{
		throw 20;
	}

	int value = 0;
	auto incr_value = [&value]() { value++; };
	auto print_value = [&value]() { std::cout << value << std::endl; };
	incr_value();
	print_value();
	
	f();
	return 0;
}

