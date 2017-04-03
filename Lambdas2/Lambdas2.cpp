// Lambdas2.cpp : Defines the entry point for the console application.
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

void print_modulo(const vector<int>& v, ostream& os, int m)
// output v[i] to os if v[i]%m==0
{
	for_each(begin(v), end(v),
		[&os, m](int x) { if (x%m == 0) os << x << '\n'; }
	);
}

int main()
{
	vector<int> counts = { 1,2,4,56,44 };
	print_modulo(counts, cout, 2);
    return 0;
}

