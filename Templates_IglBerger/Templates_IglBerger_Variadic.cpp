// Templates_IglBerger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// // Solution 1: Tail recursion
// template<typename T1, typename T2>
// auto max(T1 const& a, T2 const& b)
// {
//     return (a < b ? b : a);
// }

// template<typename T1, typename T2, typename... Ts>
// auto max(T1 const& a, T2 const& b, Ts const&... values)
// {
//     return max(max(a, b), values...);
// }

// Solution 2: constexpr C++17
// template<typename T1, typename T2>
// auto max(T1 const& a, T2 const& b)
// {
//     return (a < b ? b : a);
// }

// template<typename T1, typename T2, typename... Ts>
// auto max(T1 const& a, T2 const& b, Ts const&... values)
// {
//     if constexpr( sizeof...(Ts) > 0U ) {
//         return max(max(a, b), values...);
//     }
//     else {
//         return (a > b ? a : b);
//     }
// }

// Solution 3. Tail recursion
// template < typename T>
// T  const& max(T const& a)
// {
//     return a;
// }

// template < typename T, typename... Ts>
// auto  max(T const& a, Ts const&... values)
// {
//     auto const& b = max( values... );
//     return (a < b ? b :a );
// }

// Solution 4. constexpr.
template < typename T, typename... Ts>
auto  max(T const& a, Ts const&... values)
{
    if constexpr( sizeof...(Ts) == 0U ) {
        return a;
    }
    else {
        auto const& b = max( values... );
        return (a < b ? b :a );
    }
}
int main()
{
    std::cout << "Hello variadic World!\n";
    std::cout << max(1, 5) << "\n";
    std::cout << max(3U, 2U) << "\n";
    std::cout << max(1.2, 2.3) << "\n";
    std::cout << max(1.2, -4) << "\n";
    std::cout << max(5, 2.8) << "\n";
    
    std::cout << max(1, 5, 4) << "\n";
    std::cout << max(1, -1.3F, 2.3) << "\n";
}
