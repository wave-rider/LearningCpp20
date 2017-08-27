// Auto.cpp : Defines the entry point for the console application.
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

template<int I>
struct Num
{
	static const int c = I;
	decltype(I) _member;
	Num() : _member(c) {}
};


class Engine
{
public:
	static const int max_power_level = 100;
	void set_power_level(int power_level) {}
};

class JetPlane
{
	string _model;
	vector<Engine> _engines;
public:
	JetPlane(const string& model = string()) : _model(model)
	{}

	const string& model() const { return _model; }

	vector<Engine>& engines() { return _engines; }
};

template<typename X, typename Y>
auto multiply(X x, Y y) -> decltype(x * y)
{
	return x * y;
}

int main()
{
	auto a = 1, b = 2;
	auto i = 1, *ptr = &a, &ref = b;
	b = 111;
	cout << ref << endl;
	
	volatile long clock = 0;
	auto c = clock;		// c is not volatile
	bool  result = is_volatile<decltype(c)>::value;
	if (!result)
	{
		cout << "c is not volatile";
	}

	long  d = 12;
	//bool r2 = is_volatile<d>::value;

	JetPlane fleet[7];
	auto e = fleet;		// type of e is JetPlane*
	if ((is_same<decltype(e), JetPlane*>::value) == true) {
		auto& f = fleet;		// type of f is JetPlane(&)[10] - a reference
		//auto c = JetPlane(&)[20];
		if ((is_same<decltype(f), JetPlane(&)[7]>::value) == true)
		{
			//cin >> a;
		}
	}

	vector<int> aa;
	decltype(aa) bb;
	bb.push_back(10);
	decltype(aa)::iterator iter = aa.end(); //vector<int>::

	int a1 = 20;
	decltype(a1++) bbb=21;
	cout << "bbbb:" << bbb << endl;
	cout << "a1:" << a1 << endl;


	int ip;
	decltype(Num<1>::c, ip) var = ip; // varis int& ??????
	cout << typeid(decltype(var)).name() << endl;
	cout << "is_reference:" << is_reference<decltype(var)>::value << endl;
	cout << "is_lvalue_reference:" << is_lvalue_reference<decltype(var)>::value << endl;
	cout << "is_rvalue_reference:" << is_rvalue_reference<decltype(var)>::value << endl;

	
	return 0;
}

