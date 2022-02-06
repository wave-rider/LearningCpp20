// SpanViewArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.nextptr.com/question/qa1339936119/the-stdspan-as-a-view-of-an-array

#include <iostream>
#include <span>
#include <vector>
#include <array>

using namespace std;
int64_t add(std::span<int> s) {
    int64_t sum = 0;
    for (auto i : s) //iterate over s
        sum += i;
    return sum;
}

int main()
{
    /* An array. The size is implicit. */
    int iArr[] = { 1,1,1,1 };
    std::cout << add(iArr) << "\n"; //4

    /* A dynamic array.
       Requires explicit pointer and size to construct span. */
    int* iPtr = new int[4];
    iPtr[0] = iPtr[1] = iPtr[2] = iPtr[3] = 1;
    std::cout << add({ iPtr, 4 }) << "\n"; //4

    /* An std::array */
    std::array<int, 4> isArr = { 1, 1, 1, 1 };
    std::cout << add(isArr) << "\n"; //4

    /* A std::vector.
       Requires explicit pointer and size to construct span.*/
    std::vector<int> iVec = { 1,1,1,1 };
    std::cout << add({ &iVec[0], 4 }) << "\n"; //4

    int largeArr[100000];
    auto sum2 = add({ largeArr + 400, 100 });
    auto sum3 = add({ &largeArr[400], 100 });
    auto sum4 = add(&largeArr[400]);
    auto sum5 = add(std::span(&largeArr[400], 100));
}

