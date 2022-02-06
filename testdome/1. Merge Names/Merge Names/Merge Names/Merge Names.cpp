
/*Implement the unique_names method.When passed two vectors of names, 
it will return a vector containing the names that appear in either or both vectors.The returned vector should have no duplicates.
For example, calling unique_names(std::vector<std::string>{"Ava", "Emma", "Olivia"}, 
std::vector<std::string>{"Olivia", "Sophia", "Emma"}) should return a vector containing Ava, 
Emma, Olivia, and Sophia in any order.*/
#include <tuple>
#include <stdexcept>
#include <string>
#include<math.h>
using namespace std;

#include <iostream>
#include <vector>
#include <set>

set<string> addToSet(const vector<string>& v, set<string>& s)
{
    // Traverse the Vector
    for (string x : v) {

        // Insert each element
        // into the Set
        if (s.find(x) == s.end())
        {
            s.insert(x);
        }
    }

    // Return the resultant Set
    return s;
}

std::vector<std::string> unique_names(const std::vector<std::string>& names1, const std::vector<std::string>& names2)
{
    set<string> s;
    addToSet(names1, s);
    addToSet(names2, s);
    vector<string> result;
    for (auto r : s)
    {
        result.push_back(r);
    }

    return result;
}



#ifndef RunTests
int main()
{
    std::vector<std::string> names1 = { "Ava", "Emma", "Olivia" };
    std::vector<std::string> names2 = { "Olivia", "Sophia", "Emma" };

    std::vector<std::string> result = unique_names(names1, names2);
    for (auto element : result)
    {
        std::cout << element << ' '; // should print Ava Emma Olivia Sophia
    }
    return 0;
}
#endif

