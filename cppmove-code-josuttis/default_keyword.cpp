#include <iostream>
class MyClass {
public:
    int value;
    MyClass() = default;  // Explicitly requesting a default constructor
};

int main() {
    MyClass obj1;  // Object created with implicitly generated default constructor
    MyClass obj2{};  // Object created with explicitly generated default constructor

    std::cout << obj1.value << std::endl;  // Value is uninitialized
    std::cout << obj2.value << std::endl;  // Value is default-initialized to 0

    return 0;
}