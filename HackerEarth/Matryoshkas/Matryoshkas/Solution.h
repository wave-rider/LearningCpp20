#pragma once
#include "Doll.h"

class Solution
{
public:
	Solution();
	int solve(int* sizes);
	void printDoll(shared_ptr<Doll> const& doll, int index);
	void printDolls(std::vector<shared_ptr<Doll>> const& dolls);
};

