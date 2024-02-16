// Templates_Iglberger_Print.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <ostream>

template< typename T, size_t N >
constexpr size_t dimensionof(T (&array)[N])
{
    return N;
}

// void print( std::ostream& os )
// { }

template< typename T, typename... Ts> // Variadic Template Parameter
void print(std::ostream& os, T const& value, Ts const&... values) //Parameter Pack
{
    os << " " << value;
    if ( sizeof...(Ts) > 0U)
    {
        print( os, values...); // Tail recursion (c++11)
    }
}
#include <iostream>

int main()
{
    print(std::cout, 42);
    print(std::cout, "Hello\n");

    print(std::cout, 42, 3.14, '\n');
    print(std::cout, "Two", "words");

    constexpr size_t N = dimensionof("Hello n");
    std::cout << " N = " << N << "\n";

    
}

