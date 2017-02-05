//
//  MyClass.hpp
//  CppTestApp
//
//  Created by admin on 2/3/17.
//  Copyright © 2017 admin. All rights reserved.
//

#ifndef MyClass_hpp
#define MyClass_hpp

#include <stdio.h>
#include <iostream>
#include "Picachu.hpp"

class MyClass
{
public:
    int x;
	const Picachu& PicaReference;
	Picachu* PicaPointer;
	MyClass(const Picachu& picaReference, Picachu* picaPointer);
};

#endif /* MyClass_hpp */
