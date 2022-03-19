#include <vector>
#include <stdexcept>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;
int countInternalNodes(const std::vector<int>& tree)
{
    std::set<int> hash;
    for (int x : tree) {
        hash.insert(x);
    }

    int result = 0;// std::count_if(vInt.begin(), vInt.end(), [](int x) {return x % 3 == 0; });

    for (int i=0; i< tree.size(); i++)
    { 
        if (hash.find(i) != hash.end())
        {
            result++;
        }
    }

    return result;
}

#ifndef RunTests
int main()
{
    std::vector<int> tree;
    tree.push_back(1);
    tree.push_back(3);
    tree.push_back(1);
    tree.push_back(-1);
    tree.push_back(3);

    std::cout << countInternalNodes(tree);
}
#endif