// Templates_IglBerger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


template<typename T1, typename T2>
constexpr auto max(T1 const& a, T2 const& b) 
{
    return (a < b ? b : a);
}


int main()
{
    std::cout << "Hello World!\n";
    std::cout << max(1, 5) << "\n";
    std::cout << max(3U, 2U) << "\n";
    std::cout << max(1.2, 2.3) << "\n";
    std::cout << max(1.2, -4) << "\n";
    auto result = max(1.2, -4);
    auto max2 = max(5, 2.8);
    std::cout << max(5, 2.8) << "\n";

}
