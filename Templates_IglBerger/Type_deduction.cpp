#include <ostream>
#include <iostream>

template <typename... Pack1, typename... Pack2>
void f(Pack1... pack1, Pack2... pack2)
{
    std::cout << "\n"
        << "Number of params in pack 1: " << sizeof...(Pack1) << "\n"
        << "Number of params in pack 2: " << sizeof...(Pack2) << "\n"
        << "\n";
}

int main()
{
    f(1,2,3,4); // All parameters will be added to pack 2
    f<int, int>(1,2,3,4); // 2 parameters in each pack
    f<int, int>(1,2,3,4,5); // 2 parameters in each pack
    f<int, int>(1,2,3,4,5,6); // 2 parameters in the first pack, 4 in the second
    f<int>(1,2,3,4,5,6); // 1 parameters in the first pack, 5 in the second
    f<int, int,int, int>(1,2,3,4); // All parameters in the first pack
    return EXIT_SUCCESS;
}