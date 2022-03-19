#include <vector>
#include <stdexcept>
#include <iostream>
#include <set>

using namespace std;

class MovingTotal
{
public:

	void append(const std::vector<int>& list)
	{
		for (auto it = list.begin(); it != list.end(); ++it)
		{
			three_elems.push_back(*it);
			if (three_elems.size() == 3)
			{
				auto total = three_elems[0] + three_elems[1] + three_elems[2];
				hash.insert(total);
				three_elems.erase(three_elems.begin());
			}
		}
	}

	bool contains(int total)
	{
		auto pos = hash.find(total);
		return pos != hash.end();
	}

private:
	std::vector<int> three_elems;
	std::vector<int> totals;
	set<int> hash;
};

#ifndef RunTests
int main()
{
	MovingTotal movingTotal;

	std::vector<int> first;
	first.push_back(1);
	first.push_back(2);
	first.push_back(3);
	first.push_back(4);

	movingTotal.append(first);

	std::cout << movingTotal.contains(6) << std::endl;
	std::cout << movingTotal.contains(9) << std::endl;
	std::cout << movingTotal.contains(12) << std::endl;
	std::cout << movingTotal.contains(7) << std::endl;

	std::vector<int> second;
	second.push_back(5);
	movingTotal.append(second);

	std::cout << movingTotal.contains(6) << std::endl;
	std::cout << movingTotal.contains(9) << std::endl;
	std::cout << movingTotal.contains(12) << std::endl;
	std::cout << movingTotal.contains(7) << std::endl;
}
#endif