#pragma once
enum class DollState {
	OPEN, CLOSED
};

#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Doll;

class Doll {
public:
	std::shared_ptr<Doll> nestedDoll;
	DollState dollState;
	int dollSize;

	Doll(DollState state, int dollSize);
	Doll(const Doll& doll);
	Doll& operator=(const Doll& copy);
	int availableDollSize();
};
