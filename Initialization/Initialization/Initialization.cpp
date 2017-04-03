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

	return 0;
}

