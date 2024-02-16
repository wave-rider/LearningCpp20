//https://www.jviotti.com/2022/05/05/debugging-the-cxx-standard-library-on-macos.html

#include <unordered_map>
#include <string>
#include <iostream>

int main() {
  std::unordered_map<std::string, std::string> test;
  test.insert({"foo", "bar"});
  test.insert_or_assign("foo", "baz");
  std::cout << test.at("foo") << "\n";
  return 0;
}

// clang++ -nostdinc++ -nostdlib++ \
// -isystem /Users/admin/llvm-project/build/include/c++/v1 \
//   -L /Users/admin/llvm-project/build/lib -l c++ \
//   -Wl,-rpath,/Users/admin/llvm-project/build/lib \
//   -std=c++17 \
//   StdLib_Test.cpp -o test
