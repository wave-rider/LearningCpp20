#pragma once
#include <string>
using namespace std;
class Utils
{
public:
	Utils();
	static string ident(string arg); // string passed by value (copied into arg)
	~Utils();
};

