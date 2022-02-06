/*
Implement function countNumbers that accepts a sorted vector of unique integers and,
efficiently with respect to time used, counts the number of vector elements that are less than
the parameter lessThan.

For example, for vector v containing { 1, 3, 5, 7 }, countNumbers(v, 4) should return 2 because
there are two vector elements less than 4
*/

// The solution: https://github.com/walidAbbassi/TestDomeCpp/blob/master/SortedSearch.cpp
#include <vector>
#include <stdexcept>
#include <iostream>

// My attempt
// int countNumbers(const std::vector<int>& sortedVector, int lessThan)
//{
//    int last_elem = sortedVector.back();
//    bool indexNotFound = true;
//    if (lessThan > last_elem)
//        return sortedVector.size();
//    if (lessThan < sortedVector[0]) {
//        return 0;
//    }
//    int currentIndex = sortedVector.size() - 1;
//    while (indexNotFound)
//    {
//        if (currentIndex >= 0 && sortedVector[currentIndex] < lessThan)
//        {
//            if (currentIndex + 1 < sortedVector.size() && sortedVector[currentIndex + 1] > lessThan)
//            {
//                indexNotFound = false;
//                break;
//            }
//        }
//        currentIndex = currentIndex / 2;
//    }
//
//
//    return indexNotFound == false ? currentIndex + 1 : 0;
//
//}

static int countNumbers(const std::vector<int>& sortedVector, int lessThan)
{
    //throw std::logic_error("Waiting to be implemented");
    auto result = std::lower_bound(std::begin(sortedVector), std::end(sortedVector), lessThan);

    // return the distance between two iterators
    return std::distance(std::begin(sortedVector), result);
}

#ifndef RunTests
int main()
{
    std::vector<int> v{ 1, 3, 5, 7 };
    std::cout << countNumbers(v, 4);
}
#endif
