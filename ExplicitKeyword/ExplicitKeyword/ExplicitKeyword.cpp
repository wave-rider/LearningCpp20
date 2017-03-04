// ExplicitKeyword.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class Date {
	int d, m, y;
public:
	explicit Date(int dd = 0, int mm = 0, int yy = 0);
	// ...
};


int main()
{
	Date d1{ 15 }; // OK: considered explicit
	Date d2 = Date{ 15 }; // OK: explicit
	Date d3 = { 15 }; // error : = initialization does not do implicit conversions
	Date d4 = 15; // error : = initialization does not do implicit conversions

	return 0;
}

