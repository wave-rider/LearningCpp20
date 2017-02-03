//
//  main.cpp
//  Enumerations
//
//  Created by admin on 2/3/17.
//  Copyright © 2017 admin. All rights reserved.
//

#include <iostream>
#include "Enums.h"
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Color col = Color::green;
    Traffic_light light = Traffic_light::red;
    cout << col << endl; // It works with old enum
    cout << static_cast<std::underlying_type<Traffic_light>::type>(light) << endl;
    return 0;
}
