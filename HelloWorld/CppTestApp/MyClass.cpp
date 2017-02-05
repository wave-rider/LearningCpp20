//
//  MyClass.cpp
//  CppTestApp
//
//  Created by admin on 2/3/17.
//  Copyright © 2017 admin. All rights reserved.
//

#include "MyClass.hpp"

MyClass::MyClass(const Picachu& picaReference, Picachu* picaPointer) : PicaReference{picaReference}, PicaPointer{picaPointer}
{
	x = 0;
}