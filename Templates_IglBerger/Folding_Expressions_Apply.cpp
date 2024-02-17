#include <ostream>
#include <iostream>
struct S
{
    int i;
};

std::ostream& operator<<( std::ostream& os, S s )
{
    return os << s.i;
}

S operator+(S lhs, S rhs)
{
    std::cout << "Adding " << lhs << " and " << rhs << "\n";
    return S{ lhs.i + rhs.i };
}

S operator+(int lhs, S rhs)
{
    std::cout << "Adding " << lhs << " and " << rhs << "\n";
    return S{ lhs + rhs.i };
}

S operator+(S lhs, int rhs)
{
    std::cout << "Adding " << lhs << " and " << rhs << "\n";
    return S{ lhs.i + rhs };
}

template< typename Fn, typename... Ts >
auto apply( Fn fn, Ts const&... values )
{
    static_assert(std::conjunction_v<std::is_invocable<Fn,Ts>...> );
    //return ( ..., fn(values));  // Unary left fold 
    return (fn(values), ...);  // Unary right fold  - doesn't work if the values is empty
}

int square( int i ) 
{ 
    std::cout << "Square of " << i << "\n";
    return i*i; 
}

int main()
{
    auto const result = apply( square, 1, 2, 3, 4 );
    std::cout << "Result: " << result << "\n";

    return EXIT_SUCCESS;
}