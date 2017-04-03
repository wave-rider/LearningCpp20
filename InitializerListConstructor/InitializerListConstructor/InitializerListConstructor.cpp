// InitializerListConstructor.cpp : Defines the entry point for the console application.
//
//http://en.cppreference.com/w/cpp/utility/initializer_list
#include "stdafx.h"
#include <iostream>
#include <vector>

template <class T>
struct S {
	std::vector<T> v;
	S(std::initializer_list<T> l) : v(l) {
		std::cout << "constructed with a " << l.size() << "-element list\n";
	}
	void append(std::initializer_list<T> l) {
		v.insert(v.end(), l.begin(), l.end());
	}
	std::pair<const T*, std::size_t> c_arr() const {
		return { &v[0], v.size() };  // copy list-initialization in return statement
									 // this is NOT a use of std::initializer_list
	}
};

template <typename T>
void templated_fn(T) {}

int main()
{
	S<int> s = { 1, 2, 3, 4, 5 }; // copy list-initialization
	s.append({ 6, 7, 8 });      // list-initialization in function call
	std::cout << "The vector size is now " << s.c_arr().second << " ints:\n";

    return 0;
}
// http://stackoverflow.com/questions/17787394/why-doesnt-stdinitializer-list-provide-a-subscript-operator
