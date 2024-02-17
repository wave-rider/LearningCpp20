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

template< typename... Ts >
auto sum( Ts const&... values )
{
    //return ( ... + values);  // Unary left fold - doesn't work if the values is empty
    //return ( values + ...);  // Unary right fold  - doesn't work if the values is empty

    //return ( 0 + ... + values ); // Binary left fold
    return ( values + ... + 0 ); // Binary right fold
}

int main()
{
    auto const result = sum( S{1}, S{2}, S{3}, S{4} );
    std::cout << "Result: " << result << "\n";

    return EXIT_SUCCESS;
}