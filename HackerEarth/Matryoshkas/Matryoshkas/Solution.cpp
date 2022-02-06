#include "Solution.h"
#include "Doll.h"

Solution::Solution() {};

void Solution::printDoll(shared_ptr<Doll> const& doll, int index)
{
	cout << "Doll at index " << index << " Size: " << doll->dollSize << " av size " << doll->availableDollSize() << endl;

	if (doll->nestedDoll != nullptr)
	{
		printDoll(doll->nestedDoll, -1);
	}
}

void Solution::printDolls(std::vector<shared_ptr<Doll>> const& dolls)
{
	cout << "Dolls" << endl;
	for (int d = 0; d < dolls.size(); d++)
	{
		//cout << "Doll " << d << " ====== " << endl;
		printDoll(dolls[d], d);
	}
}

int Solution::solve(int* sizes)
{
	//int num;
	std::vector<shared_ptr<Doll>> dolls;
	//cin >> num;										// Reading input from STDIN
	//cout << "Input number is " << num << endl;		// Writing output to STDOUT
	int num = 7;

	for (int i = 0; i < num; i++) {
		//cin >> dollSize;
		Doll doll(DollState::CLOSED, sizes[i]);
		dolls.push_back(make_shared<Doll>(doll));
	}

	printDolls(dolls);

	bool allDollsInPlace = false;
	//cin >> dollSize;

	int index = 0;
	int openCount = 0;
	bool dollMoved = false;
	while (!allDollsInPlace) {
		auto doll = *dolls[index];
		if (index >= dolls.size()) {
			index = 0;
			if (dollMoved == false) {
				allDollsInPlace = true;
			}
			dollMoved = false;
		}
		else
		{
			//Doll rightDoll = *dolls[index + 1];
			//int righDollAvailableSize = rightDoll.availableDollSize();
			if (index + 1 < dolls.size() &&
				dolls[index + 1]->availableDollSize() > 1
				&& dolls[index + 1]->availableDollSize() > doll.dollSize) {
				cout << "Move doll pos:" << index << " size:" << doll.dollSize << " to the pos " << index + 1;
				if (dolls[index + 1]->dollState == DollState::CLOSED) {
					openCount++;
					dolls[index + 1]->dollState = DollState::OPEN;
				}
				auto removeDoll = *dolls[index];
				dolls.erase(dolls.begin() + index);
				if (!dolls[index]->nestedDoll)
					dolls[index]->nestedDoll = make_shared<Doll>(removeDoll);
				else
					*dolls[index]->nestedDoll = removeDoll;
				dolls[index]->dollState = DollState::CLOSED;
				dollMoved = true;
				index = 0;
			}
			else {
				if (index > 0)
				{
					Doll leftDoll = *dolls[index - 1];
					int leftDollAvailableSize = leftDoll.availableDollSize();
					if (leftDollAvailableSize > 1 && leftDollAvailableSize > doll.dollSize) {
						cout << "Move doll pos:" << index << " size:" << doll.dollSize << " to the pos " << index - 1;
						if (leftDoll.dollState == DollState::CLOSED) {
							leftDoll.dollState = DollState::OPEN;
							openCount++;
						}
						auto removeDoll = *dolls[index];
						dolls.erase(dolls.begin() + index);
						if (!dolls[index - 1]->nestedDoll)
							dolls[index - 1]->nestedDoll = make_shared<Doll>(removeDoll);
						else
							*dolls[index - 1]->nestedDoll = removeDoll;
						dolls[index - 1]->dollState = DollState::CLOSED;
						dollMoved = true;
						index = 0;
					}
					else {
						index++;
					}
				}
				else
					index++;
			}
		}
		printDolls(dolls);
	}
	cout << "openCount:" << openCount;
	return openCount;
}