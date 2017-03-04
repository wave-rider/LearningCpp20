// WeakPointer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// http://en.cppreference.com/w/cpp/memory/weak_ptr

#include <iostream>
#include <memory>

std::weak_ptr<int> gw;

void f()
{
	std::cout << "use_count == " << gw.use_count() << ": ";
	if (auto spt = gw.lock()) { // Has to be copied into a shared_ptr before usage
		std::cout << *spt << "\n";
	}
	else {
		std::cout << "gw is expired\n";
	}
}

int main()
{
	{
		auto sp = std::make_shared<int>(42);
		gw = sp;

		f();
	}

	f();
}