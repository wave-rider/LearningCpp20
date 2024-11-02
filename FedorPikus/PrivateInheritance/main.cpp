//
//  main.cpp
//  PrivateInheritance
//
//  Created by Admin on 02/11/2024.
//

#include <iostream>

class Empty {
public:
    void useful_function();
};

class Composed {
    int i;
}; // sizeof(Composed) == 4

class Composed1 {
    int i;
    Empty e;
}; // sizeof(Composed1) == 8

class Composed2 {
    Empty e;
}; // sizeof(Composed2) == 1


class Derived : private Empty {
    
}; // sizeof(Derived) == 1

class Derived1 : private Empty {
    int i;
}; // sizeof(Derived1) == 4

class Derived2 : public Empty {
    int i;
}; // sizeof(Derived2) == 4


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "sizeof(Empty)" << sizeof(Empty) << std::endl;
    std::cout << "sizeof(Composed)" << sizeof(Composed) << std::endl;
    std::cout << "sizeof(Composed1)" << sizeof(Composed1) << std::endl;
    std::cout << "sizeof(Composed2)" << sizeof(Composed2) << std::endl;
    std::cout << "sizeof(Derived)" << sizeof(Derived) << std::endl;
    std::cout << "sizeof(Derived1)" << sizeof(Derived1) << std::endl;
    std::cout << "sizeof(Derived2)" << sizeof(Derived2) << std::endl;

    return 0;
}
