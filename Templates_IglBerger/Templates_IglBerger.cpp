// Templates_IglBerger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


template<typename T>
T max(T const& a, T const& b)   // (1)
//    -> typename std::common_type<T, U>::type
{
    /*if (a < b)
        return b;  
    else
        return a;*/
    return a < b ? b : a;
}

template< >
int max<int>(int const& a, int const& b)   // (1S)
//    -> typename std::common_type<T, U>::type
{
    /*if (a < b)
        return b;
    else
        return a;*/
    return a < b ? b : a;
}

template<typename T, typename U>
auto max(T const& a, U const& b)   // (2)
{
    /*if (a < b)
        return b;
    else
        return a;*/
    return (a < b ? b : a);
}

int max(int a, int b)   // (3)
{
    /*if (a < b)
        return b;
    else
        return a;*/
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
