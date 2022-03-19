// Initialization.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

struct Work {
	string author;
	string name;
	int year;
};

int main()
{
	int a{ 1 };
	char* p{ nullptr };
	

	Work s9{ "Beethoven",
		"Symphony No. 9 in D minor, Op. 125; Choral",
		1824
	}; //memberwise initialization
	Work currently_playing{ s9 }; // copy initialization. 
	Work none{}; // default init... ==>> "","",0
	s9.author = "Guess who?";
	cout << currently_playing.author << " " << s9.author << " " << currently_playing.author;
	Work test; //"", "", unknown
	Work default{}; // "", "", 0
	static Work here; // "", "", 0
	Work* freeStore = new Work; //"", "", unknown

	// For Stroustrup Chapter 6.
	unsigned char c1 = 64; // well defined: a char has at least 8 bits and can always hold 64
	unsigned char c2 = 1256; // implementation-defined: truncation if a char has only 8 bits
	cout << "unsigned char size:" << sizeof(unsigned char) << endl;
	cout << "Result:" << c1 << ' ' << c2;
	

	return 0;
}

