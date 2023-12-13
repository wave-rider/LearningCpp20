//********************************************************
// The following code example is taken from the book
//  C++ Move Semantics - The Complete Guide
//  by Nicolai M. Josuttis (www.josuttis.com)
//  http://www.cppmove.com
//
// The code is licensed under a
//  Creative Commons Attribution 4.0 International License
//  http://creativecommons.org/licenses/by/4.0/
//********************************************************


#include <iostream>
#include <type_traits>
#include <optional>

class B
{
  public:
  int u;//std::string s;
  std::optional<int> test;
  B() = default;
  B(const B&) = default;
  B(B&&)  = default;
};

int main()
{
  std::cout << std::boolalpha;
  std::cout << "1:" <<std::is_nothrow_default_constructible<B>::value << '\n';
  std::cout << "2:" <<std::is_nothrow_copy_constructible<B>::value << '\n';
  std::cout << "3:" <<std::is_nothrow_move_constructible<B>::value << '\n';
  std::cout << "4:"  <<std::is_nothrow_copy_assignable<B>::value << '\n';
  std::cout << "5:" <<std::is_nothrow_move_assignable<B>::value << '\n';
  B test;
  test.test = 89;
}

// This will make all lines in the output to be true
// However changing the class definition to std::string will
// produce the output as from the book
// true
//false
//true
//false
//true
